class Solution {
public:
    string frequencySort(string s) {
        string result;
        
        unordered_map<char, int> freqMap;
        
        for (int i = 0; i < s.size(); i++) {
            freqMap[s[i]]++;
        }
        
        vector<pair<char,int>> freqMapElements(freqMap.begin(), freqMap.end());
        
        std::sort(freqMapElements.begin(), freqMapElements.end(), comp);
        
        for (int i = 0; i < freqMapElements.size(); i++) {
            for (int j = 0; j < freqMapElements[i].second; j++) {
                result += freqMapElements[i].first;
            }
        }
        
        return result;
    }
    
private:
    
    static bool comp(const pair<char,int> &p1, const pair<char,int> &p2) {
        return p1.second > p2.second;
    }
};