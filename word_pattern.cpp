class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        if (pattern.empty() || str.empty())
            return false;
        
        int i = 0;
        unordered_map<char, string> charMap;
        unordered_set<string> valuesSeen;

        std::istringstream iss(str);
        
        for(std::string value; iss >> value;) {

            if (i >= pattern.size())
                return false;

            char key = pattern[i];
            
            if (value.empty())
                return false;

            if (charMap.find(key) != charMap.end()) {
                if (value != charMap[key])
                    return false;
            } else {
                if (valuesSeen.find(value) != valuesSeen.end())
                    return false;
                
                valuesSeen.insert(value);
                charMap[key] = value;
            }
        
            i++;
        }
        
        return i == pattern.size();
    }
};