class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        map<string, bool> * wordMap = new map<string, bool>();
        map<string, vector<string>> * memo = new map<string, vector<string>>();
        
        for (int i = 0; i < wordDict.size(); i++) {
            (*wordMap)[wordDict[i]] = true;
        }

        vector<string> result;
        
        wordBreakHelper(s, *wordMap, *memo, result);
        delete wordMap;
        delete memo;
        return result;
    }
    
private:
    
    void wordBreakHelper(string s, map<string, bool> &wordDict, 
                         map<string, vector<string>> &memo,
                         vector<string> &result) {

        if (s.size() == 0) {
            return;
        }

        string temp = "";

        if (wordDict.find(s) != wordDict.end()) {
            result.push_back(s);
        }

        for (int i = 1; i < s.size(); i++) {
            if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
                
                vector<string> substr_result;
                temp = s.substr(0, i);
                
                if (memo.find(s.substr(i)) != memo.end()) {
                    substr_result = memo[s.substr(i)];
                } else {
                    wordBreakHelper(s.substr(i), wordDict, memo, substr_result);
                }
                
                for (int i = 0; i < substr_result.size(); i++) {
                    result.push_back(temp + " "+ substr_result[i]);
                }
            }
        }

        memo[s] = result;
    }
};