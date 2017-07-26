#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string cur_str = "";
        map<char, string> numToStringMap;
        
        buildNumToStringMap(numToStringMap);
        letterCombinationsHelper(numToStringMap, digits,
                                 0, result, cur_str);
        
        return result;
    }
    
private:
    
    void letterCombinationsHelper(map<char, string> &numToStringMap,
                                 string digits, int str_index, vector<string> &result,
                                  string cur_str) {
        
        if (str_index == digits.size()) {
            if (cur_str.size() > 0) {
                result.push_back(cur_str);
            }
            return;
        }
        
        map<char, string>::iterator it = numToStringMap.find(digits[str_index]);

        if(it == numToStringMap.end()) {
            result.clear();
            return;
        }
        
        string stringMapping = numToStringMap[digits[str_index]];
        
        for (int i = 0; i < stringMapping.size(); i++) {
            
            cur_str.push_back(stringMapping[i]);
            letterCombinationsHelper(numToStringMap, digits, str_index+1,
                                     result, cur_str);
            cur_str.pop_back();
        }
    }
    
    void buildNumToStringMap(map<char, string> &numToStringMap) {
        numToStringMap['2'] = "abc";
        numToStringMap['3'] = "def";
        numToStringMap['4'] = "ghi";
        numToStringMap['5'] = "jkl";
        numToStringMap['6'] = "mno";
        numToStringMap['7'] = "pqrs";
        numToStringMap['8'] = "tuv";
        numToStringMap['9'] = "wxyz";
    }
};
