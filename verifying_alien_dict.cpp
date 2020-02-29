class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char, int> charIndexMap;
        
        for (int i = 0; i < order.size(); i++)
        {
            charIndexMap[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); i++)
        {
            if (!isAlienSorted(words[i-1], words[i], charIndexMap))
            {
                return false;
            }
        }
        
        return true;
    }
    
private:
    
    bool isAlienSorted(string &str1, string &str2,
                       unordered_map<char, int> &charIndexMap)
    {
        int len = min(str1.size(), str2.size());
        
        for (int i = 0; i < len; i++)
        {    
            if (charIndexMap[str1[i]] > charIndexMap[str2[i]])
            {
                return false;
            }
            else if (charIndexMap[str1[i]] < charIndexMap[str2[i]])
            {
                return true;
            }
        }
        
        return str1.size() <= str2.size();
    }
};