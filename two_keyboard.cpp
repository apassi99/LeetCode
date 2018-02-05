class Solution {
public:
    int minSteps(int n) {
        
        if (n <= 1) {
            return 0;
        }
        
        //Initialize memo table
        int result = 0;
        int * mem = new int[n+1];
        mem[0] = 0;
        mem[1] = 0;
        
        for (int i = 2; i <= n; i++) {
            // Find the largest multiple
            for (int j = i-1; j >=1; j--) {
                if (i % j == 0) {
                    mem[i] = mem[j] + (i/j);
                    break;
                }
            }
        }
        
        result = mem[n];
        delete [] mem;
        return result;
    }
};