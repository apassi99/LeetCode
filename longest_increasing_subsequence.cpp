class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.empty())
            return 0;
        
        int result = 1;
        int len = nums.size();
        int dp[len];
        
        dp[len-1] = 1;
        
        for (int i = len - 2; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i+1; j < len; j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                } else if (nums[i] == nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                    break;
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
        
    }
};