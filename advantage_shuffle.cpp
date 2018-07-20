class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        vector<int> result;
        sort(A.begin(), A.end());
        set<int> usedIndices;
        
        for (int i = 0; i < B.size(); i++) {
            int idx = getMinimumMaxIdx(B[i], A);
            result.push_back(A[idx]);
            A.erase(A.begin() + idx);
        }
        
        return result;
    }
    
private:
    
    int getMinimumMaxIdx(int val, vector<int> &A) {
        
        int i = 0;
        int j = A.size() - 1;
        int result = 0;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            
            if (A[mid] > val) {
                result = mid;
                j = mid - 1;
            } else {
                i = mid+1;
            }
        }
        
        return result;
    }
};