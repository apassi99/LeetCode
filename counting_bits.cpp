class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> result;
        
        if (num < 0) {
            return result;
        }
        
        int cur = 1;
        result.push_back(0);
        
        for (int i = 1; i <= num; i++) {
            cur = computeNextCur(i);
            result.push_back(result[i-cur] + 1);
        }
        
        return result;
    }

private:
    
    int computeNextCur(int num) {
        int result = 1;
        while (result < num) {
            if (result * 2 > num) {
                return result;
            }
            result *= 2;
        }
        return result;
    }
};