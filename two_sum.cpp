class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> numbersSeen;
        vector<int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if ( numbersSeen.find(target - nums[i]) != numbersSeen.end() ) {
                v.push_back(numbersSeen[target - nums[i]]);
                v.push_back(i);
                return v;
            }
            
            numbersSeen[nums[i]] = i;
        }
        
        return v;
    }
};
