class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        set<int> visitedNodes;
        
        for (int i = 0; i < M.size(); i++) {
            int numFriends = 0;
            dfs(i, M, visitedNodes, numFriends);
            result += (numFriends > 0) ? 1 : 0;
        }
        
        return result;
    }
    
private:
    
    void dfs(const int node, vector<vector<int>>& M, set<int> &visitedNodes, int &numFriends) {
        
        if (visitedNodes.find(node) != visitedNodes.end()) {
            return;
        }
        
        if (node >= M.size()) {
            return;
        }
        
        visitedNodes.insert(node);
        
        for (int i = 0; i < M[node].size(); i++) {
            if (M[node][i] == 1)
                dfs(i, M, visitedNodes, numFriends);
        }
        
        numFriends++;
    }
};