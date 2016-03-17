class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> l;

        combinationSumHelper(&v, &l, n, k, 0, 1);
        return v;
    }
    
private:

    void combinationSumHelper(vector<vector<int>> * v, vector<int> * l, int n, int k, int sum, int i) {
        if (sum == n && l->size() == k) {
            v->push_back(*l);
            return;
        }

        if (sum > n) {
            return;
        }

        for (int j = i; j <= 9; j++) {
            l->push_back( j );
            combinationSumHelper(v, l, n, k, sum + j, j+1);
            l->pop_back();
        }
    }
};
