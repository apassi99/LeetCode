class Solution {
public:
    string longestPalindrome(string s) {
        string maxSubStr = "";
        longestPalindromeHelper(s, maxSubStr);
        return maxSubStr;
    }
    
private:
    
    void longestPalindromeHelper(string &s, string &maxSubStr) {
        
        int len = s.size();
        
        if (len == 0)
            return;
        if (len == 1) {
            if (maxSubStr.size() < len) {
                maxSubStr = s;
            }
            return;
        }
        
        for (int i = 1; i <= len; i++) {
            string cur = s.substr(0,i);
            if (isPalindrome(cur)) {
                if (cur.size() > maxSubStr.size()) {
                    maxSubStr = cur;
                }
            }
        }

        string remain = s.substr(1, len);
        
        if (remain.size() >= maxSubStr.size()) {
            longestPalindromeHelper(remain, maxSubStr);
        }
    }
    
    bool isPalindrome(string &s) {
        int i1 = 0;
        int i2 = s.size() - 1;
        
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