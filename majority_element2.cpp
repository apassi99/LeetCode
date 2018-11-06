class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        
        if (nums.empty())
            return result;
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int prev = nums[0];

        for (int i = 0; i < len; i++) {

            if (prev == nums[i])
                count++;
            
            if (prev != nums[i]) {
                if (count > (len / 3)) {
                    result.push_back(prev);
                }
                count = 1;
            }
            
            if (i == len - 1) {
                if (count > (len / 3)) {
                    result.push_back(nums[i]);
                }
                count = 1;
            }
            
            prev = nums[i];
        }
        
        return result;
    }
};