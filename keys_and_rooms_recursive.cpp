class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int N = rooms.size();
        set<int> visitedNodes;
        set<int> visitingNodes;
        bool result = N > 0;
        
        dfs(0, rooms, visitedNodes, visitingNodes);
        
        for (int i = 0; i < N; i++) {
            if (visitedNodes.find(i) == visitedNodes.end()) {
                return false;
            }
        }
        
        return result;
    }
    
private:
    
    void dfs(int node, vector<vector<int>>& G,
             set<int> &visitedNodes, set<int> &visitingNodes) {
        
        if (visitingNodes.find(node) != visitingNodes.end())
            return;
        
        if (visitedNodes.find(node) != visitedNodes.end())
            return;
        
        if (node >= G.size())
            return;
        
        visitingNodes.insert(node);
        
        for (int i = 0; i < G[node].size(); i++) {
            dfs(G[node][i], G, visitedNodes, visitingNodes);
        }
        
        visitingNodes.erase(node);
        visitedNodes.insert(node);
    }
};