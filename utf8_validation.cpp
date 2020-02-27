class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int idx     = 0;
        int numOnes = 0;
        int len     = (int) data.size();
        
        while (idx < len) {
            
            numOnes = getNums(data[idx]);
            idx++;
            
            if (numOnes == 0) {
                continue;
            }
            
            if (numOnes >= 5 || numOnes == 1) {
                return false;
            }
            
            if (numOnes - 1 <= len - idx) {
                
                while(numOnes > 1) {
                    if (((data[idx] & 0xFF) & 0xC0) != 0x80) {
                        return false;
                    }
                
                idx++;
                numOnes--;
                }
            }
            else {
                return false;
            }
        }
        
        return true;
        
    }
    
private:
    
    int getNums(int val) {
        
        int numOnes = 0;
        
        for (int i = 7; i >= 0; i--) {
            if (((val & 0xFF) & (1 << i)) == (1 << i)) {
                numOnes++;
            } else {
                break;
            }
        }
        
        return numOnes;
    }
};