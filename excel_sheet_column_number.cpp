// Related to question Excel Sheet Column Title
// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//    A -> 1
//    B -> 2
//    C -> 3
//    Z -> 26
//    AA -> 27
//    AB -> 28 

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        int temp = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            int num = s[i] - 'A' + 1;
            number += temp * num;
            temp *= 26;
        }
        
        return number;
    }
};
