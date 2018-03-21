class Solution {
public:
    int numDecodings(string s) {
        
        if (s.size() > 0 && s[0] == '0') {
            return 0;
        }
        
        map<int, int> * memo = new map<int, int>();
        
        int result = numDecodingsHelper(s, 0, *memo);
        return (result != -1) ? result : 0;
    }

private:

    int numDecodingsHelper(string &s, int index, map<int, int> &memo) {
        
        if (index >= s.size()) {
            return 0;
        }
        
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }
        
        if (index == s.size() - 1) {
            int value = char_to_int(s[index]);
            int result = (value > 0 && value < 10) ? 1 : 0;
            memo[index] = result;
            return memo[index];
        }
        
        if (index == s.size() - 2) {
            int tens_place = char_to_int(s[index]);
            int ones_place = char_to_int(s[index+1]);
            int num = (tens_place * 10) + ones_place;
            
            if (in_range(num)) {
                if (tens_place == 0) {
                    memo[index] = 0;
                    return 0;
                } else if (ones_place == 0) {
                    memo[index] = 1;
                    return 1;
                } else {
                    memo[index] = 2;
                    return 2;
                }
            } 
        }

        
        int result = 0;

        int tens_place = char_to_int(s[index]);
        int ones_place = char_to_int(s[index+1]);
        int num = (tens_place * 10) + ones_place;

        int numDecodings1 = numDecodingsHelper(s, index+1, memo);
        int numDecodings2 = numDecodingsHelper(s, index+2, memo);

        if (numDecodings1 == -1 || numDecodings2 == -1 || num == 0) {
            return -1;
        }
        
        if (in_range(tens_place)) {
            result += numDecodings1;
            
            if (in_range(num)) {
                result += numDecodings2;
            }
        }

        memo[index] = result;
        return result;    
    }
    
    int char_to_int(char c) {
        return c - '0';
    }
    
    bool in_range(int n) {
        return (n > 0 && n < 27);
    }
};

// Example: 
//  '9119' -> '9' func('119') + '91' func('19')  -> 3 
//   '119' -> '1' func('19')  + '11' func('9')   -> 2 + 1 -> 3
//   '19'  -> '1' func('9')   + '19' func('')    -> 2
//    '9'  -> '9' func('')
// 9, 1, 1, 9
// 9, 11, 9
// 9, 1, 19


// '1234' -> '1' + func('234') + '12' + func('34')
// '234'  -> '2' + func('34')  + '23' + func('4')
//  '34'  -> '3' + func('4')   + '34' + func('')
//   '4'  ->  '' + ''