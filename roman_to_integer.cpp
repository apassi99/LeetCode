class Solution {
public:
    int romanToInt(string s) {
        
        map<string, int> intMap;
        string indices [] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        buidIntMap(&intMap);
        
        int result = 0;
        int i = 12;
        int index = 0;
        int len = s.size();
        
        while (index < len) {

            if (s.substr(index, 1) == indices[i]) {
                result += intMap[indices[i]];
                index++;
            } else if (s.substr(index, 2) == indices[i]) {
                result += intMap[indices[i]];
                index += 2;
            } else if (i != 0) {
                i--;
            } else {
                return 0;
            }
        }
        
        return result;

    }
    
private:
    
    void buidIntMap(map<string, int> * intMap) {
        (*intMap)["I"]    = 1;
        (*intMap)["IV"]   = 4;
        (*intMap)["V"]    = 5;
        (*intMap)["IX"]   = 9;
        (*intMap)["X"]    = 10;
        (*intMap)["XL"]   = 40;
        (*intMap)["L"]    = 50;
        (*intMap)["XC"]   = 90;
        (*intMap)["C"]    = 100;
        (*intMap)["CD"]   = 400;
        (*intMap)["D"]    = 500;
        (*intMap)["CM"]   = 900;
        (*intMap)["M"]    = 1000;
    }
};