// Given two strings s and t, write a function to determine if t is an anagram of s.
// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.
// Note:
// You may assume the string contains only lowercase alphabets.

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }
        
        int charOccurence[26] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            charOccurence[s[i] - 'a'] += 1;
        }
        
        for (int i = 0; i < t.size(); i++) {
            charOccurence[t[i] - 'a'] += -1;
        }
        
        for (int i = 0; i < t.size(); i++) {
            if ( charOccurence[s[i] - 'a'] != 0 )
                return false;
        }
        
        return true;
    }
};
