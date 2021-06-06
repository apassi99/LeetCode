class Solution {
public:
    string convert(string s, int numRows) {
        
        int rowNum = 0;
        int countDir = 1;
        string result;
        unordered_map<int, string> rowToStrMap;
        
        for (int i = 0; i < (int) s.size(); i++)
        {
            rowToStrMap[rowNum] += s[i];
            
            if (numRows == 1)
                countDir = 0;
            else if (rowNum == numRows - 1)
                countDir = -1;
            else if (rowNum == 0)
                countDir = 1;
            
            rowNum += countDir;
            
        }
        
        for (int i = 0; i < numRows; i++)
        {
            result.append( rowToStrMap[i] );
        }
        
        return result;
    }
};
