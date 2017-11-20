class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int result = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[abs(nums[i]) -1] < 0) {
                result = abs(nums[i]);
                break;
            }
            
            nums[abs(nums[i]) -1] *= -1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        
        return result;
    }
};