class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        if (numCourses <= 1) {
            return true;
        }
        
        vector<vector<int>> G;
        int visitedNodes[numCourses];
        int visitingNodes[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            visitedNodes[i] = 0;
            visitingNodes[i] = 0;
            vector<int> temp;
            for (int j = 0; j < numCourses; j++) {
                temp.push_back(0);
            }
            G.push_back(temp);
        }
        
        for (int i = 0; i < prerequisites.size(); i++) {
            G[prerequisites[i].second][prerequisites[i].first] = 1;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (visitedNodes[i] != 1) {
                if (!canFinishHelper(i, G, visitedNodes,
                                    visitingNodes, numCourses)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    
    bool canFinishHelper(int node, vector<vector<int>> &G, int * visitedNodes,
                         int * visitingNodes, int numCourses) {
        
        if (visitingNodes[node] == 1) {
            return false;
        }
        
        visitingNodes[node] = 1;
        
        for (int i = 0; i < numCourses; i++) {
            if (visitedNodes[i] != 1 && G[node][i] == 1) {
                if (!canFinishHelper(i, G, visitedNodes,
                                    visitingNodes, numCourses)) {
                    return false;
                }
            }
        }
        visitingNodes[node] = 0;
        visitedNodes[node] = 1;
        return true;
    }
};