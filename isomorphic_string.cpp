// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while 
// preserving the order of characters. No two characters may map to the 
// same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
            
        map<char, int> mapcountS;
        map<char, int> mapcountT;
        map<char, char> mapChar;
        
        for (int i = 0; i < s.size(); i++) {
            mapcountS[s[i]] += 1;
            mapcountT[t[i]] += 1;
            
            try {
                if (mapChar.at(s[i]) != t[i])
                    return false;
            } catch (const std::out_of_range& oor) {
                mapChar[s[i]] = t[i];
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            if ( mapcountS[s[i]] != mapcountT[t[i]] ) {
                return false;
            }
        }
        
        return true;
    }
};
