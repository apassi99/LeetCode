class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> memo;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        for (int i = 0; i < m; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(-1);
            }
            memo.push_back(temp);
        }

        return uniquePathsWithObstaclesHelper(m-1, n-1, memo, obstacleGrid);
    }
    
private:

    int uniquePathsWithObstaclesHelper(int m, int n, 
                                       vector<vector<int>> &memo,
                                      vector<vector<int>> &obstacleGrid) {
        
        if (m < 0 || n < 0) {
            return 0;
        }
        
        if (obstacleGrid[m][n] == 1) {
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
            memo[m-1][n] = uniquePathsWithObstaclesHelper(m-1, n, memo, obstacleGrid);
            t1 = memo[m-1][n];
        }
        if (n > 0) {
            memo[m][n-1] = uniquePathsWithObstaclesHelper(m, n-1, memo, obstacleGrid);
            t2 = memo[m][n-1];
        }
        
        return t1 + t2;
    }
};