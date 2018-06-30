class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int prev_idx = -1;
        int prev_idx2 = -1;
        int prev_idx3 = -1;
    
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (prev_idx != -1 && nums[i] == nums[prev_idx])
                continue;
            
            prev_idx = i;

            int first = nums[i];
            int i1 = i+1;
            int i2 = nums.size() - 1;
            
            prev_idx2 = -1;
            prev_idx3 = -1;

            while (i1 < i2) {

                
                if (first + nums[i1] + nums[i2] == 0) {
                    
                    if (prev_idx2 == -1 || prev_idx3 == -1 || 
                        nums[i1] != nums[prev_idx2] || 
                        nums[i2] != nums[prev_idx3]) {

                        vector<int> temp;
                        temp.push_back(first);
                        temp.push_back(nums[i1]);
                        temp.push_back(nums[i2]);
                        result.push_back(temp);
                    }
                    
                    prev_idx3 = i2;
                    prev_idx2 = i1;
                    i1++;
                    i2--;
                }

                else if (first + nums[i1] + nums[i2] > 0) {
                    prev_idx3 = i2;
                    i2--;
                }

                else {
                    prev_idx2 = i1;
                    i1++;
                }
            }
        }
        
        return result;
    }
};