class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> dictT;
        unordered_map<char,int> windowMap;
        
        for (int i = 0; i < t.size(); i++)
        {
            dictT[t[i]]++;
        }
        
        int left  = 0;
        int right = 0;
        
        int ans_minLength = INT_MAX;
        int ans_left      = -1;
        int ans_right     = -1;
        
        int charsMatchFound    = 0;
        int requiredChars      = dictT.size();
        
        while (right < s.size())
        {
            char currentChar = s[right];
            
            windowMap[currentChar]++;

            if (dictT[currentChar] == windowMap[currentChar])
            {
                charsMatchFound++;
            }
            
            while (left <= right && charsMatchFound == requiredChars)
            {
                if (ans_minLength > right - left + 1)
                {
                    ans_minLength = right - left + 1;
                    ans_left      = left;
                    ans_right     = right;
                }
                
                windowMap[s[left]]--;
                
                if (dictT[s[left]] > windowMap[s[left]])
                {
                    charsMatchFound--;
                }
                
                left++;
            }
            
            right++;
        }
        
        if (ans_left != -1 && ans_right != -1)
        {
            return s.substr(ans_left, ans_minLength);
        }
        else
        {
            return "";
        }
    }
};