class Solution {
public:
    int longestPalindromeSubseq(string s) {
        unordered_map<string, int> memo;
        return longestPalindromeSubseq_helper(s, 0, s.size()-1, memo);
    }

private:
    
    int longestPalindromeSubseq_helper(string &s, int start, int end,
                                      unordered_map<string, int> &memo) {

        if (start > end) 
            return 0;
        
        if (start == end)
            return 1;
        
        string key = to_string(start) + "-" + to_string(end);
        
        if (memo.find(key) != memo.end())
            return memo[key];
        
        if (s[start] == s[end]) {
            memo[key] = 2 + longestPalindromeSubseq_helper(s, start+1, end-1, memo);
        } else {
            memo[key] = max(longestPalindromeSubseq_helper(s, start+1, end, memo),
                            longestPalindromeSubseq_helper(s, start, end-1, memo));
        }
        
        return memo[key];

    }
};