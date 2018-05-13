class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int result = 0;
        int prev_end = 0;
        int start = 0;
        
        if (timeSeries.empty() || duration <= 0) {
            return result;
        }
        
        for (int i = 0; i < timeSeries.size(); i++) {
            start = (i == 0) ? 0 : timeSeries[i];
            result += duration;
            
            if (timeSeries[i] < prev_end) {
                result = result - (prev_end - start);
            }
            
            prev_end = timeSeries[i] + duration;
        }
        
        return result;
    }
};