class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        
        for (int row = 1; row <= numRows; row++)
        {
            vector<int> rowValues(row, 1);
            result.push_back(rowValues);
            
            for (int i = 1; i < row-1; i++)
            {
                result[row-1][i] = result[row-2][i] + result[row-2][i-1];
            }
        }
        
        return result;
    }
};