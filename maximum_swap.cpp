class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        
        char maxNumPos [digits.size()];
        int cur = digits.size() - 1;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] > digits[cur]) {
                cur = i;
            }
            maxNumPos[i] = cur;
        }
        
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] < digits[maxNumPos[i]]) {
                char temp = digits[i];
                digits[i] = digits[maxNumPos[i]];
                digits[maxNumPos[i]] = temp;
                break;
            }
        }
        
        return stoi(digits);
    }
};