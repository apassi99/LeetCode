class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return helper(nums, 0, nums.size() -1);
    }
    
private:
    
    int helper(vector<int>& nums, int s, int e)
    {
        if (s > e)
            return -1;
        
        int mid = (s + e) / 2;
        
        int prevVal = (mid - 1 >= 0) ? nums[mid-1] : INT_MAX;
        int nextVal = (mid + 1 < nums.size()) ? nums[mid+1] : INT_MAX;
        
        if (nums[mid] == nextVal)
        {
            if (mid % 2 == 0)
                return helper(nums, mid+1, e);
            else
                return helper(nums, s, mid-1);
        }
        if (nums[mid] == prevVal)
        {
            if (mid % 2 == 0)
                return helper(nums, s, mid-1);
            else
                return helper(nums, mid+1, e);
        }
        
        if (nums[mid] != nextVal &&
            nums[mid] != prevVal)
        {
            return nums[mid];
        }
        
        return -1;
    }
};