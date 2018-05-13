class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        if (n == 0) return 1;
        if (n == 1) return 10;
        
        int cpy_n = n;
        int result = 1;

        if (n > 9) {
            cpy_n = 9;
        }

        for (int i = 0; i < cpy_n; i++) {
            result *= (i+1 == cpy_n) ? 9 : (9 - i);
        }

        return result + countNumbersWithUniqueDigits(n-1);
    }
};