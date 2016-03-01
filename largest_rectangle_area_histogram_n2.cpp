class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxarea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            
            int min = heights[i];
            int minCount = 1;
            
            maxarea = max(maxarea, minCount * min);
            
            for (int j = i+1; j < heights.size(); j++) {
                
                if (heights[j] == 0) {
                    maxarea = max(maxarea, minCount * min);
                    break;
                }
                
                if (heights[j] < min) {
                    min = heights[j];
                }
                
                minCount++;
                
                maxarea = max(maxarea, minCount * min);
            }
            
            maxarea = max(maxarea, minCount * min);
        }
        
        return maxarea;
    }
};
