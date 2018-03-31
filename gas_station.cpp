class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gasRemaining = 0;
        int numGasStations = gas.size();
        int i = 0, j = 0, nextGasStation = 0, startIndex = 0;
        bool completeCircle = true;
        
        while(i < numGasStations) {
            j = i;
            gasRemaining = 0;
            completeCircle = true;
            startIndex = i;
            do {
                gasRemaining += gas[j];
                i++;
                
                if (gasRemaining < cost[j]) {
                    completeCircle = false;
                    break;
                }
                gasRemaining = gasRemaining - cost[j];
                j = (j+1) % numGasStations;
            } while (j != startIndex);

            if (completeCircle) {
                return startIndex;
            }
        }
        
        return -1;
    }
};