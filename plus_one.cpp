class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> result;
        int carry = 0;
        
        for (int i = 0; i < digits.size(); i++) {
            
            int inc = (i > 0) ? 0 : 1;
            int sum = digits[digits.size() - i - 1] + carry + inc;
            
            result.push_back(sum % 10);
            carry = (sum > 9) ? 1 : 0;
            
        }
        
        if (carry > 0) {
            result.push_back(carry);
        }
        
        std::reverse(result.begin(), result.end()); 
        return result;
    }
};