class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        
        vector<string> result;
        
        dfs(word, true, 0, "", result);
        
        return result;
    }
    
    void dfs(string &word, bool useNum, int s, string abbr_str, vector<string> &result)
    {
        if (s >= word.size())
        {
            result.push_back(abbr_str);
            return;
        }
        
        string newAbbrStr = "";
        
        for (int i = s; i < word.size(); i++)
        {
            if (useNum)
            {
                newAbbrStr = abbr_str + std::to_string(i - s + 1);
                dfs(word, false, i+1, newAbbrStr, result);
            }
        }
        
        newAbbrStr = abbr_str + word.substr(s, 1);
        dfs(word, true, s+1, newAbbrStr, result);
    }
};