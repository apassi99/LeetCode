class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        map<string, bool> * wordMap = new map<string, bool>();
        map<string, bool> * memo = new map<string, bool>();
        
        for (int i = 0; i < wordDict.size(); i++) {
            (*wordMap)[wordDict[i]] = true;
        }
        
        bool result = wordBreakHelper(s, *wordMap, *memo);
        delete wordMap;
        delete memo;
        return result;
    }
    
private:
    
    bool wordBreakHelper(string s, map<string, bool> &wordDict, map<string, bool> &memo) {

        if (s.size() == 0) {
            return false;
        }

        if (wordDict.find(s) != wordDict.end()) {
            memo[s] = true;
            return true;
        }

        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        for (int i = 1; i < s.size(); i++) {
            if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
                if (wordBreakHelper(s.substr(i), wordDict, memo)) {
                    memo[s] = true;
                    return memo[s];
                }
            }
        }

        memo[s] = false;
        return false;
    }

// 'ABCD' -> 'A' func('BCD')  |  'AB' func('CD') | 'ABC' func('D')
//  'BCD' -> 'B' func('CD")   |   'C' func('D')
//   'CD' -> 'C' func('D')    |   'D' func('')
};