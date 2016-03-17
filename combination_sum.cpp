class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    
        vector<vector<int>> v;
        vector<int> l;
        
        sort(candidates.begin(), candidates.end());
        
        combinationSumHelper(&v, &l, &candidates, 0, target, 0);
        return v;
    }
    
private:

    void combinationSumHelper(vector<vector<int>> * v, vector<int> * l, vector<int> * candidates, int sum, int target, int i) {
        if (sum == target && l->size() > 0) {
            v->push_back(*l);
            return;
        }
        
        if (sum > target) {
            return;
        }
        
        for (int j = i; j < candidates->size(); j++) {
            l->push_back( (*candidates)[j] );
            combinationSumHelper(v, l, candidates, sum + (*candidates)[j], target, j);
            l->pop_back();
        }
    }
};
