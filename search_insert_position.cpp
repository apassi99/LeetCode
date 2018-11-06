class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = INT_MAX;
        searchInsertHelper(nums, 0, nums.size() - 1, target, &result);
        return (result == INT_MAX) ? nums.size() : result;
    }
    
private:
    
    void searchInsertHelper(vector<int> &nums, int start, int end, int target, int * index) {
        
        if (start > end)
            return;
        
        int mid = (start + end) / 2;
        
        if (nums[mid] == target) {
            *index = mid;
        } else if (nums[mid] > target) {
            *index = mid;
            searchInsertHelper(nums, start, mid-1, target, index);
        } else {
            *index = mid + 1;
            searchInsertHelper(nums, mid + 1, end, target, index);
        }
        
    }
};