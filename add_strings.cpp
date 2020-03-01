class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string result = "";
        
        int numIter  = max(num1.size(), num2.size());
        int lastIdx1 = num1.size() - 1; 
        int lastIdx2 = num2.size() - 1;
        int caryVal  = 0;
        
        for (int i = 0; i < numIter; i++)
        {
            int n1  = (lastIdx1 >= 0) ? num1[lastIdx1] - '0' : 0;
            int n2  = (lastIdx2 >= 0) ? num2[lastIdx2] - '0' : 0;
            int sum = n1 + n2 + caryVal;
            
            caryVal = sum / 10;
            
            result += to_string(sum % 10);
            
            lastIdx1--;
            lastIdx2--;
        }
        
        if (caryVal > 0) {
            result += to_string(caryVal);
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};