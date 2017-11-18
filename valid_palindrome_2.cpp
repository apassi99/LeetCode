class Solution {
public:
    bool validPalindrome(string s) {
        
        int i1 = 0;
        int i2 = s.size() - 1;
        int prev_i1 = -1;
        int prev_i2 = -1;
        bool skippedOnce = false;
        bool retry = false;
        
        while (i1 < i2) {
            
            if (s[i1] != s[i2]) {
                
                if (skippedOnce) {
                    if (prev_i1 == prev_i2 || retry) 
                        return false;
                    else {
                        i1 = prev_i1;
                        i2 = prev_i2;
                        retry = true;
                        continue;
                    }
                }
                
                skippedOnce = true;
                
                if (s[i1+1] == s[i2])  {
                    
                    if (s[i1] == s[i2-1]) {
                        prev_i1 = i1+1;
                        prev_i2 = i2-2;
                    }
                    
                    i1=i1+2;
                    i2--;
                } else if ( s[i1] == s[i2-1] ) {
                    i1++;
                    i2 = i2-2;
                } else {
                    return false;
                }
                
            } else {
                i1++;
                i2--;
            }
        }
        
        return true;
    }
};