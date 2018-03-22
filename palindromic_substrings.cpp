class Solution {
public:
    int countSubstrings(string s) {

        int count = 0;
        int len = s.size();
        
        if (len <= 1) {
            return len;
        }
        
        for (int i = 1; i <= s.size(); i++) {
            if (isPalindrome(s.substr(0, i))) {
                count++;
            }
        }
        
        return count + countSubstrings(s.substr(1, len));

    }

private:
    
    bool isPalindrome(string s) {

        int len = s.size();
        int i1 = 0;
        int i2 = len-1;
        
        while (i1 < i2) {
            if (s[i1] != s[i2]) {
                return false;
            }
            i1++;
            i2--;
        }
        
        return true;
    }
};