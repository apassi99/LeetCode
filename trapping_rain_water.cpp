class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        
        int max_elem = -1;
        
        int maxLeft[height.size()];
        int maxRight[height.size()];
        
        for (int i = 0; i < height.size(); i++) {
            maxLeft[i] = max_elem;
            max_elem = max(max_elem, height[i]);
        }
        
        max_elem = -1;
        
        for (int i = height.size() - 1; i >= 0; i--) {
            maxRight[i] = max_elem;
            max_elem = max(max_elem, height[i]);
        }
        
        int sum = 0;
        
        for (int i = 0; i < height.size(); i++) {
            int min_elem = min(maxLeft[i], maxRight[i]);
            
            if (min_elem != -1 && min_elem > height[i]) {
                sum = sum + ( min_elem - height[i]);
            }
        }
        
        return sum;
    }
};
