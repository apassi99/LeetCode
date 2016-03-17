class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> l;
        
        combineHelper(&v, l, n, k, 0, 1);
        
        return v;
    }
    
private:

    void combineHelper(vector<vector<int>> * v, vector<int> l, int n, int k, int i, int j) {
        if ( i == k ) {
            v->push_back(l);
            return;
        }
        
        for (int a = j; a <= n; a++) {
            l.push_back(a);
            combineHelper(v, l, n, k, i+1, a+1);
            l.pop_back();
        }
        
    }
};
