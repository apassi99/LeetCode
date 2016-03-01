class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxarea = 0;
        stack<int> s;
        
        int i = 0;
        while ( i < heights.size() ) {
            
            if (s.size() == 0 || heights[i] >= heights[s.top()]) {
                s.push(i++);
            }
            
            else {
                int top = s.top();
                s.pop();
                
                int len = ( s.empty() ) ? i : i - s.top() - 1;
                maxarea = max(maxarea, heights[top] * len);
            }
            
        }
        
        while ( !s.empty() ) {
            int top = s.top();
            s.pop();
            
            int len = ( s.empty() ) ? i : i - s.top() - 1;
            maxarea = max(maxarea, heights[top] * len);
        }
        
        return maxarea;
    }
};
