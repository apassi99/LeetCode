class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        
        partitionHelper(&result, &cur, s);
        return result;
    }
    
private:

    void partitionHelper(vector<vector<string>> * result, vector<string> * cur, string s) {
        
        if (s.size() == 0) {
            result->push_back(*cur);
        }
        
        for (int i = 1; i <= s.size(); i++) {
            
            if (isPalindrome(s.substr(0, i))) {
                cur->push_back(s.substr(0, i));
                partitionHelper(result, cur, s.substr(i));
                cur->pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }
        
        int l = 0;
        int h = s.size() - 1;
        
        while (l < h) {
            if (s[l++] != s[h--])
                return false;
        }
        
        return true;
    }
};
