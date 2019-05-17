class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;

        unordered_map<int, int> freqMap;
        
        for (int i = 0; i < nums.size(); i++) {
            freqMap[nums[i]]++;
        }
        
        vector<pair<int,int>> freqMapContents(freqMap.begin(), freqMap.end());
        
        std::sort(freqMapContents.begin(), freqMapContents.end(), comp);
        
        for (int i = 0; i < freqMapContents.size(); i++) {
            if (i < k) {
                result.push_back(freqMapContents[i].first);
            }
        }
        
        return result;
    }
    
private:
    
    static bool comp(const pair<int,int> &p1, const pair<int,int> &p2) {
        return p1.second > p2.second;
    }
};