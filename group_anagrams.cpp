#include <stdlib.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        map<string, int> stringToIndexMap;
        
        bool groupFound = false;
        
        for (int i = 0; i < strs.size(); i++) {

            int temp_arr[26] = {0};
            
            for (int j = 0; j < strs[i].size(); j++) {
                temp_arr[strs[i][j] - 'a'] += 1;
            }
            
            cout << strs[i] << endl;
            string temp_str = int_array_to_string(temp_arr, 26);
            
            map<string, int>::iterator it;
            it = stringToIndexMap.find(temp_str);
            
            if (it != stringToIndexMap.end()) {
                result[stringToIndexMap[temp_str]].push_back(strs[i]);
            } else {
                vector<string> temp;
                temp.push_back(strs[i]);
                result.push_back(temp);
                stringToIndexMap[temp_str] = result.size() - 1;
            }
        }

        return result;
    }
    
private:
    
    string int_array_to_string(int int_array[], int size_of_array) {
        
        ostringstream oss("");

        for (int i = 0; i < size_of_array; i++)
            oss << int_array[i];

        cout << oss.str() << endl;
        
        return oss.str();
    }
};