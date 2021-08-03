class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        vector<string> result;
        
        unordered_set<string> seen;
        unordered_map<string,int> counterMap;
        
        for (int i = 0; i < names.size(); i++)
        {
            int counter = counterMap[names[i]];
            
            string newName = names[i];
            
            while (seen.find(newName) != seen.end())
            {
                counter += 1;
                newName = names[i] + "(" + to_string(counter) + ")";
            }
            
            counterMap[names[i]] = counter;
            seen.insert(newName);
            
            result.push_back(newName);
        }
        
        return result;
    }
};