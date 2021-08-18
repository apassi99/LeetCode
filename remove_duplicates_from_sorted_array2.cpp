class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int curIdx = -1;
        int count   = 0;
        int lastVal = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++)
        {
            nums[curIdx+1] = nums[i];
            
            if (lastVal == nums[i])
                count++;
            else
                count = 1;
            
            if (i < 2 || count <= 2)
            {
                curIdx++;
            }
            
            lastVal = nums[i];
        }
        
        return curIdx + 1;
    }
};