class Solution {
public:
    int jump(vector<int>& nums) {

        int result = 0, closestIdx = -1, lastIdx = nums.size() - 1;

        unordered_map<int, int> minJumpMap;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if(lastIdx - i <= nums[i]) {
                minJumpMap[i] = 1;
            } else {
                int min_jump = INT_MAX;
                int startIdx = min(i+nums[i], lastIdx);
                
                for (int j = startIdx; j >= i; j--) {
                    if (minJumpMap.find(j) != minJumpMap.end()) {
                        min_jump = min(minJumpMap[j], min_jump);

                        if (min_jump == 1)
                            break;
                    }
                }

                if (min_jump != INT_MAX) {
                    minJumpMap[i] = 1 + min_jump;
                }
            }
        }

        return minJumpMap[0];
    }
};