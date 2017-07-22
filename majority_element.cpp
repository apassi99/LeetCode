#include <map>

using std::map;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int majorityElem = 0;
        int maxCount = 0;
        map<int, int> * numCountMap = new map<int, int>();

        for (int i = 0; i < nums.size(); i++) {
            (*numCountMap)[nums[i]] = (*numCountMap)[nums[i]] + 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            if ((*numCountMap)[nums[i]] > maxCount) {
                maxCount = (*numCountMap)[nums[i]];
                majorityElem = nums[i];
            }
        }

        delete numCountMap;
        return majorityElem;
    }
};
