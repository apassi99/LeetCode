class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> freqMap;
        
        for (int i = 0; i < s.size(); i++)
        {
            freqMap[s[i]]++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (freqMap[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};