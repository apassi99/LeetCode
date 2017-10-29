class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> result;
        
        for (int i = 0; i < words.size(); i++) {
            if (isInSameRow(words[i]))
                result.push_back(words[i]);
        }
        
        return result;
    }
    
private:
    
    bool isInSameRow(string word) {
        
        unordered_set<char> row1 ( {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'} );
        unordered_set<char> row2 ( {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'} );
        unordered_set<char> row3 ( {'z', 'x', 'c', 'v', 'b', 'n', 'm'} );
        
        int row1Seen = 0, row2Seen = 0, row3Seen = 0;
        
        
        for (int i = 0; i < word.size(); i++) {
            
            if (row1.find( tolower(word[i]) ) != row1.end()) {
                row1Seen = 1;
            } else if (row2.find( tolower(word[i]) ) != row2.end()) {
                row2Seen = 1;
            } else if (row3.find( tolower(word[i]) ) != row3.end()) {
                row3Seen = 1;
            }
        }
        
        return (row1Seen + row2Seen + row3Seen) == 1;
    }
};