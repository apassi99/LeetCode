class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result;
        int low = INT_MAX;
        int high = INT_MIN;
        
        searchRangeHelper(nums, 0, nums.size()-1, target, low, high);
        
        if (low == INT_MAX && high == INT_MIN) {
            low = -1;
            high = -1;
        }

        result.push_back(low);
        result.push_back(high);
        
        return result;
    }
    
private:
    
    void searchRangeHelper(vector<int> &nums, int i, int j,
                      int target, int &low, int &high) {
        
        if (i > j || i < 0 || j >= nums.size()) {
            return;
        }
        
        int mid = (i + j) / 2;
        
        if (nums[mid] == target) {
    
            low = min(low, mid);
            high = max(high, mid);
    
            searchRangeHelper(nums, i, mid-1, target, low, high);
            searchRangeHelper(nums, mid+1, j, target, low, high);
        } 
        
        else if (nums[mid] > target) {
            searchRangeHelper(nums, i, mid-1, target, low, high);
        } else {
            searchRangeHelper(nums, mid+1, j, target, low, high);
        }
    }
};
