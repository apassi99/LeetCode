class Solution {
public:
    double myPow(double x, int n) {
        
        return (n < 0) ? 1 / pow(x, abs(n)) : pow(x, n);
    }
    
    double pow(double x, int n) {
        
        if (n == 0)
            return 1;
        
        if (x == 0 || x == 1)
            return x;
            
        if (x == -1) {
            return (n % 2 == 0) ? 1 : -1;
        }
        
        if (n % 2 == 0) {
            double ans = pow(x, n/2);
            return ans * ans;
        } else {
            return x * pow(x, n - 1);
        }
    }
};
