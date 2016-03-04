class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int l = 0;
        int h = nums.size() - 1;
        int min_num = 0x7fffffff;
        
        while (l < h) {
            
            int mid = (l + h) / 2;
            
            if (l == h || l == h - 1) {
                return min(nums[l], nums[h]);
            }
            
            if (nums[l] < nums[h]) {
                return nums[l];
            } else if (nums[mid] > nums[h]) {
                l = mid;
            } else {
                h = mid;
            }
            
            min_num = nums[mid];
        }
        
        return min_num;
    }
};
