class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWaysHelper(nums, S, 0, 0);
    }
    
private:
    
    int findTargetSumWaysHelper(vector<int>& nums, int S, int curS, int index) {
        
        if (index > nums.size()) {
            return 0;
        }
        
        if (index == nums.size()) {
            return (curS == S) ? 1 : 0;
        }
        
        int result = 0;
        
        result += findTargetSumWaysHelper(nums, S, curS + nums[index], index+1);
        result += findTargetSumWaysHelper(nums, S, curS - nums[index], index+1);
        
        return result;
    }
};