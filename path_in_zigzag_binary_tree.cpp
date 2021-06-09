#include <math.h> 

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        int value = label;
        vector<int> result;
        
        while (label >= 1)
        {
            int level     = (int) log2(label);
            int range_min = pow(2, level-1);
            int range_max = (range_min * 2) - 1;
            
            result.push_back(label);
            label = label / 2;
            
            int idx = range_max - label;
            label   = range_min + idx;
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
        
    }
};