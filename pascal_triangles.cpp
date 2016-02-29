class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        vector<int> v;
        v.push_back(1);
        
        if (numRows >= 1) {
            pascalTriangle.push_back(v);
        }
        
        if (numRows >= 2) {
            vector<int> v1;
            v1.push_back(1);
            v1.push_back(1);
            pascalTriangle.push_back(v1);
        }
        
        generateHelper(&pascalTriangle, numRows);
        
        return pascalTriangle;
    }
    
private:
    void generateHelper(vector<vector<int>> * pascalTriangle, int rowNum) {
        if (rowNum <= 2) {
            return;
        }
        
        vector<int> lastRow = pascalTriangle->back();
        vector<int> newRow;
        
        newRow.push_back(1);
        for (int i = 0; i < lastRow.size() / 2; i++) {
            newRow.push_back(lastRow[i] + lastRow[i+1]); 
        }
        
        int size = (lastRow.size() % 2) ? newRow.size() : newRow.size() - 1;
        
        for (int i = size - 1; i >= 0; i--) {
            newRow.push_back( newRow[i] );
        }
        
        pascalTriangle->push_back(newRow);
        generateHelper(pascalTriangle, rowNum - 1);
        
    }
};
