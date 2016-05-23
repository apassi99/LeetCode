// Write a function that takes a string as input and reverse only the vowels of a string.
// Example 1:
// Given s = "hello", return "holle".
// Example 2:
// Given s = "leetcode", return "leotcede".
// Subscribe to see which companies asked this question

class Solution {
public:
    string reverseVowels(string s) {
        string str = s;
        
        //char vowel[5] = { 'a', 'e', 'i', 'o', 'u'};
        map<char, int> vowels;
        vowels['a'] = 1;
        vowels['e'] = 1;
        vowels['i'] = 1;
        vowels['o'] = 1;
        vowels['u']= 1;
        
        
        int i1 = 0;
        int i2 = str.size() - 1;
        
        while (i1 < i2) {
            
            char c1 = str[i1];
            char c2 = str[i2];
            
            cout << c1 << "  " << c2 << endl;
            
            c1 = (c1 <= 'Z' && c1 >= 'A') ? c1 + ('a' - 'A') : c1;
            c2 = (c2 <= 'Z' && c2 >= 'A') ? c2 + ('a' - 'A') : c2;
            
            
            cout << c1 << "  " << c2 << endl;
            
            if( vowels[c1] == 1 && vowels[c2] == 1) {
                char temp = str[i1];
                str[i1] = str[i2];
                str[i2] = temp;
                i1++;
                i2--;
            }
            
            else if (vowels[c1] == 1) {
                i2--;
            }
            
            else if (vowels[c2] == 1) {
                i1++;
            }
            
            else {
                i1++;
                i2--;
            }
        }
        
        return str;
    }
};