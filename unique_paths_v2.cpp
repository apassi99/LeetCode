class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> memo;
        
        for (int i = 0; i < m; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }

        return uniquePathsHelper(m-1, n-1, memo);
    }
    
private:
    
    int uniquePathsHelper(int m, int n, vector<vector<int>> &memo) {
        
        if (m < 0 || n < 0) {
            return 0;
        }
        
        if (m == 0 && n == 0) {
            return 1;
        }
        
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        
        int t1 = 0;
        int t2 = 0;

        if (m > 0) {
            memo[m-1][n] = uniquePathsHelper(m-1, n, memo);
            t1 = memo[m-1][n];
        }
        if (n > 0) {
            memo[m][n-1] = uniquePathsHelper(m, n-1, memo);
            t2 = memo[m][n-1];
        }
        
        return t1 + t2;
    }
};