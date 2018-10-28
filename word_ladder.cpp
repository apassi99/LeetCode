class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet;
        int result = 0;
        
        for (int i = 0; i < wordList.size(); i++) {
            wordSet.insert(wordList[i]);
        }
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return result;
        }
        
        if (!beginWord.compare(endWord)) {
            return result;
        }

        list<string> q;
        q.push_back(beginWord);
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                if (q.front() == endWord) {
                    return result + 1;
                }
                
                string curStr = q.front();
                
                for (int idx = 0; idx < curStr.size(); idx++) {
                    char origChar = curStr[idx];
                    
                    for (int j = 0; j < 26; j++) {
                        char newChar = 'a' + j;
                        if (origChar != newChar) {
                            curStr[idx] = newChar;
                            if (wordSet.find(curStr) != wordSet.end()) {
                                q.push_back(curStr);
                                wordSet.erase(curStr);
                            }
                            curStr[idx] = origChar;
                        }
                    }
                }
                
                q.pop_front();
            }
            
            result++;
        }
        
        return 0;
        
    }
};