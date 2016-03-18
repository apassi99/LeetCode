class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> v;
        vector<int> l;

        sort(candidates.begin(), candidates.end());

        combinationSumHelper(&v, &l, &candidates, 0, target);
        return v;
    }
 
private:   
    void combinationSumHelper(vector<vector<int>> * v, vector<int> * l, vector<int> * candidates, int sum, int target) {
        if (sum == target && l->size() > 0) {
            v->push_back(*l);
            return;
        }

        if (sum > target) {
            return;
        }

        while (candidates->size() > 0) {
            
            vector<int> newBag(candidates->begin(), candidates->end());
            newBag.erase(newBag.begin());
            
            while ( candidates->size() > 1 && (*candidates)[0] == (*candidates)[1]) {
                candidates->erase(candidates->begin());
            }
            
            l->push_back( (*candidates)[0] );
            combinationSumHelper(v, l, &newBag, sum + (*candidates)[0], target);
            l->pop_back();
            
            candidates->erase(candidates->begin());
        }
    }
};
