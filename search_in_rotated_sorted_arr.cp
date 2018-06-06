class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums, 0, nums.size() - 1);
        int idx1 = searchHelper(nums, target, 0, pivot - 1);
        int idx2 = searchHelper(nums, target, pivot, nums.size()-1);
        
        return (idx1 != -1) ? idx1 : idx2;
    }
    
private:
    
    int searchHelper(vector<int> &nums, int target, int i, int j) {
        
        if (i > j || i < 0 || j >= nums.size())
            return - 1;
        
        int mid = (i + j) / 2;
        
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return searchHelper(nums, target, i, mid-1);
        else
            return searchHelper(nums, target, mid+1, j);
    }
    
    int findPivot(vector<int> &nums, int i, int j) {
        
        if (i > j || i < 0 || j >= nums.size())
            return - 1;
        
        if (i == j) {
            return i;
        }
        
        int mid = (i + j) / 2;
        
        if (nums[i] > nums[mid]) {
            return findPivot(nums, i+1, mid);
        } else if (nums[j] < nums[mid]) {
            return findPivot(nums, mid+1, j);
        }
        
        return i;
        
    }
};
