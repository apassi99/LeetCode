class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        bool returnVal = true;
        int count = 0;
        
        for (int i = 30; i >= 0; i--) {
            int mask = 3 << i;
            
            if ((n & mask) > 0) {
                count = 1;
            }

            if ((n & mask) == 0 && count != 0) {
                return false;
            } else if ((n & mask) == mask) {
                return false;
            }
        }
        
        return returnVal;
    }
};