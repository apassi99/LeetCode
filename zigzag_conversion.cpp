class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows <= 0 || numRows > s.size()) {
            return s;
        }
        
        int len = s.size();
        int count = 0;
        string returnVal = "";
        bool countDown = true;
        map<int, string> rowToStrMap;

        
        for (int i = 0; i < len; i++) {          
            rowToStrMap[count] += s[i];
            count += (numRows == 1) ? 0 : (countDown) ? 1 : -1;
            countDown = (count == numRows-1 || count == 0) ? !countDown : countDown;
            
        }
        
        for (int i = 0; i < numRows; i++) {
            returnVal.append(rowToStrMap[i]);
        }
        
        return returnVal;
    }
};