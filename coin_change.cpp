class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        map<int, int> *memo = new map<int, int>;
        int result = coinChange_helper(coins, amount, memo);
        delete memo;
        return result;
    }
    
private:

    int coinChange_helper(vector<int>& coins, int amount, map<int, int> *memo) {

        if (amount < 0 || coins.empty()) {
            return -1;
        }
        
        if (amount == 0) {
            return 0;
        }
        
        int result = INT_MAX;
        
        if ( memo->find(amount) != memo->end() ) {
            return (*memo)[amount];
        }
        
        for (int i = 0; i < coins.size(); i++) {
            
            int amountRemaining = amount - coins[i];
            
            if (amountRemaining == 0) {
                (*memo)[amount] = 1;
                return 1;
            }
            
            if (amountRemaining > 0) {

                int temp = coinChange_helper(coins, amount - coins[i], memo);
                
                if (temp != -1) {
                    result = min(temp+1, result);
                }
            }
        }
        
        if (result == INT_MAX) {
            result = -1;
        }
        
        (*memo)[amount] = result;
        return result;
    }
};
