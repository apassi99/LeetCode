class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if (nums.empty()) {
            return false;
        }
        
        int closestIdx = -1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] + i >= nums.size() - 1) {
                closestIdx = i;
            }
            
            if (closestIdx != -1 && nums[i] + i >= closestIdx) {
                closestIdx = i;
            }
        }
        
        if (nums[0] >= nums.size() - 1) {
            return true;
        }
        
        if (closestIdx != -1 && nums[0] >= closestIdx) {
            return true;
        }
        
        return false;
    }
};