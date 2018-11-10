class Solution {
public:
    int numSquares(int n) {
        
        if (n <= 0) {
            return 0;
        }
        
        if (memoTable.find(n) != memoTable.end()) {
            return memoTable[n];
        }
        
        int result = n;
        
        for (int i = 1; i < n; i++) {
            if ((i * i) == n) {
                return 1;
            } else if ((i * i) < n) {
                int temp = numSquares(n - (i*i));
                if (temp != 0)
                    result = min(temp + 1, result);
            } else {
                break;
            }
        }
        
        memoTable[n] = result;
        
        return result;
    }
    
private:
    
    unordered_map<int, int> memoTable;
};