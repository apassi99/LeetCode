class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;
   
        int revx = 0;
        int temp = x;
        
        while (temp > 0) {
            revx = (revx * 10) + (temp % 10);
            temp /= 10;
        }
        
        return revx == x;
    }
};
