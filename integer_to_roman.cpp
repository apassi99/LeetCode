class Solution {
public:
    string intToRoman(int num) {

        map<int, string> charMap;
        int indices [] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        buildCharMap(&charMap);
        
        string result = "";
        int i = 12;
        
        while (num > 0) {
            if (num - indices[i] >= 0) {
                result += charMap[indices[i]];
                num = num - indices[i];
            }  else if (i != 0) {
                i--;
            } else {
                return "";
            }
        }
        
        return result;
    }
    
private:
    
    void buildCharMap(map<int, string> * charMap) {
        (*charMap)[1]    = "I";
        (*charMap)[4]    = "IV";
        (*charMap)[5]    = "V";
        (*charMap)[9]    = "IX";
        (*charMap)[10]   = "X";
        (*charMap)[40]   = "XL";
        (*charMap)[50]   = "L";
        (*charMap)[90]   = "XC";
        (*charMap)[100]  = "C";
        (*charMap)[400]  = "CD";
        (*charMap)[500]  = "D";
        (*charMap)[900]  = "CM";
        (*charMap)[1000] = "M";
    }
};