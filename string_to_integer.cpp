class Solution {
public:
    int myAtoi(string str) {
        
        int result = 0, signFactor = 1, idx = 0;

        /* Skip initial whitespace characters. */
        while (str[idx] == ' ') { idx++; }
        
        if (str[idx] == '-') {
            signFactor = -1;
            idx++;
        } else if (str[idx] == '+') {
            idx++;
        }
        
        while (isNum(str[idx])) {

            if (result > ((INT_MAX - str[idx] + '0') / 10) ) {
                return (signFactor == 1) ? INT_MAX : INT_MIN;
            }

            result = (result * 10) + (str[idx] - '0');
            idx++;
        }
        
        if (abs(result * signFactor) != result) {
            return (signFactor == 1) ? INT_MAX : INT_MIN;
        }

        return result * signFactor;
    }
    
private:
    
    bool isNum(char c) {
        return c >= '0' && c <= '9';
    }
};
