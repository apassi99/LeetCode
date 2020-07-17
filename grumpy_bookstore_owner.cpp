class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        int result = 0;
        unordered_map<int, int> notSatisfiedSoFar;
        
        notSatisfiedSoFar[-1] = 0;
        
        for (size_t i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 1)
            {
                notSatisfiedSoFar[i] = customers[i] + notSatisfiedSoFar[i-1];
            }
            else
            {
                notSatisfiedSoFar[i] = notSatisfiedSoFar[i-1];
            }
            
        }
        
        int startIdx = X - 1;
        int maxSeen = 0;
        int w_s = -1;
        int w_e = -1;
        
        for (int i = startIdx; i < customers.size(); i++)
        {
            int notSatisfiedInWin = notSatisfiedSoFar[i] - notSatisfiedSoFar[i-X];
            
            if (maxSeen <= notSatisfiedInWin)
            {
                maxSeen = notSatisfiedInWin;
                w_e = i;
                w_s = i - X + 1;
            }
        }
        
        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 1)
            {
                if (i >= w_s && i <= w_e)
                {
                    result += customers[i];
                }
            }
            else
            {
                result += customers[i];
            }
        }
        
        return result;
    }
};
