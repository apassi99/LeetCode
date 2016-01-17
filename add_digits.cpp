class Solution {
public:
    int addDigits(int num) {
        
        if (num < 0 || num % 10 == num)
            return num;
            
        int temp = 0;
        
        while (num > 0) {
            temp += num % 10;
            num = num / 10;
        }
        
        return addDigits(temp);
    }
};
