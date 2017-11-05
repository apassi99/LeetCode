class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOccurrenceValue = 1;
        int returnValue = 0;
        int maxOccurrence = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxOccurrenceValue) {
                maxOccurrence++;
            } else {
                if (maxOccurrence > returnValue) {
                    returnValue = maxOccurrence;
                }
                maxOccurrence = 0;
            }
        }
        
        if (maxOccurrence > returnValue) {
            returnValue = maxOccurrence;
        }
        
        return returnValue;
    }
};