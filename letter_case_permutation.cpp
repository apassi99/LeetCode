class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        helper(S, 0, "", result);
        return result;
    }
    
private:
    
    void helper(string S, int idx, string cur, vector<string> &result) {
        
        if (idx >= S.size()) {
            result.push_back(cur);
            return;
        }
        
        if (S[idx] >= 'a' && S[idx] <= 'z') {
            char temp = S[idx] - 'a' + 'A';
            helper(S, idx+1, cur + temp, result);
        } else if (S[idx] >= 'A' && S[idx] <= 'Z') {
            char temp = S[idx] - 'A' + 'a';
            helper(S, idx+1, cur + temp, result);
        }

        helper(S, idx+1, cur + S[idx], result);
    }
};