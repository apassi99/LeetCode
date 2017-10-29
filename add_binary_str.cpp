class Solution {
public:
    string addBinary(string a, string b) {
        
        string result;
        int i = 0, carry = 0;
        
        while ( (i < a.size())  || (i < b.size()) ) {
            
            int n1 = (i >= a.size()) ? 0 : a[a.size() - i - 1] - '0';
            int n2 = (i >= b.size()) ? 0 : b[b.size() - i - 1] - '0';
            int sum = n1 + n2 + carry;
            result.append( std::to_string((sum % 2)));
            carry = (sum > 1) ? 1 : 0;
            i++;
        }
        
        if (carry > 0) {
            result.append( std::to_string(carry) );
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};