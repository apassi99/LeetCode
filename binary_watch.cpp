class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (numBitsSet(i) + numBitsSet(j) == num) {
                    string hr = to_string(i);
                    string min = (j <= 9) ? "0" + to_string(j) : to_string(j);
                    result.push_back(hr + ":" + min);
                }
            }
        }
        
        return result;
    }
    
private:
    
    int numBitsSet(uint32_t n) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) result++;
        }
        
        return result;
     }
};