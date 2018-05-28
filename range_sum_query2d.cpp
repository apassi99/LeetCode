class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        
        for (int i = 0; i <= matrix.size(); i++) {
            vector<int> temp;
            for (int j = 0; j <= matrix[0].size(); j++) {
                temp.push_back(0);
            }
            m_SumMatix.push_back(temp);
        }

        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                m_SumMatix[i][j] = m_SumMatix[i-1][j] + m_SumMatix[i][j-1] - m_SumMatix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_SumMatix[row2+1][col2+1] - m_SumMatix[row2+1][col1] 
            - m_SumMatix[row1][col2+1] + m_SumMatix[row1][col1];
    }

private:
    
    vector<vector<int>> m_SumMatix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */