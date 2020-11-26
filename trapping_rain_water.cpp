class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        
        vector<int> max_left, max_right;
        
        max_left.resize(height.size());
        max_right.resize(height.size());
        
        int maxHeightLeft  = 0;
        int maxHeightRight = 0;
        int minHeight      = 0;
        
        for (int i = 0; i < height.size(); i++)
        {            
            max_left[i]   = maxHeightLeft; 
            maxHeightLeft = max(height[i], maxHeightLeft);
        }
        
        for (int i = height.size() - 1; i >= 0; i--)
        {
            max_right[i]   = maxHeightRight;
            maxHeightRight = max(height[i], maxHeightRight);
        }
        
        for (int i = 0; i < height.size(); i++)
        {
            minHeight  = min(max_left[i], max_right[i]);
            result    += (minHeight > height[i]) ? minHeight - height[i]: 0;
        }
        
        return result;
    }
};