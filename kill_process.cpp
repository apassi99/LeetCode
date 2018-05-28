class Solution {
public:

    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        vector<int> result;
        
        if (pid.size() != ppid.size()) {
            return result;
        }
        
        unordered_map<int, vector<int>> parentToChildMap;
        
        for (int i = 0; i < pid.size(); i++) {
            
            if (parentToChildMap.find(ppid[i]) != parentToChildMap.end()) {
                parentToChildMap[ppid[i]].push_back(pid[i]);
            } else {
                vector<int> temp;
                temp.push_back(pid[i]);
                parentToChildMap[ppid[i]] = temp;
            }
        }
        
        killProcessHelper(parentToChildMap, result, kill);
        
        return result;
    }
    
private:

    void killProcessHelper(unordered_map<int, vector<int>> &parentToChildMap,
                           vector<int> &result, int kill) {
        
        if (parentToChildMap.find(kill) != parentToChildMap.end()) {
            
            for (int i = 0; i < parentToChildMap[kill].size(); i++) {
                killProcessHelper(parentToChildMap, result, parentToChildMap[kill][i]);
            }
        }
        result.push_back(kill);                              
    }
    
};