class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> result;
        
        if (numCourses <= 0) {
            return result;
        }
        
        vector<vector<int>> G;

        int visitedNodes[numCourses];
        int visitingNodes[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            visitedNodes[i] = 0;
            visitingNodes[i] = 0;
        }

        for (int i= 0; i < numCourses; i++) {
            vector<int> temp;
            for (int j = 0; j < numCourses; j++) {
                temp.push_back(0);
            }
            G.push_back(temp);
        }
        
        for (int i = 0; i < prerequisites.size(); i++) {
            G[prerequisites[i].second][prerequisites[i].first] = 1;
        }

        list<int> stack;
        
        for (int i = 0; i < numCourses; i++) {
            
            if (visitedNodes[i] != 1) {
                if (findOrderHelper(G, stack, visitedNodes, visitingNodes, i)) {
                    return result;
                }
            }
        }
        
        while (!stack.empty()) {
            result.push_back(stack.back());
            stack.pop_back();
        }

        //result.erase(result.begin());
        return result;
    }
    
private:
    
    bool findOrderHelper(vector<vector<int>> &G, list<int> &stack,
                         int * visitedNodes, int *visitingNodes, int node) {

        if (visitingNodes[node] == 1) {
            return true;
        }

        visitingNodes[node] = 1;
        
        for (int i = 0; i < G.size(); i++) {
            if (G[node][i] == 1 && visitedNodes[i] != 1) {
                if (findOrderHelper(G, stack, visitedNodes, visitingNodes, i)) {
                    return true;
                }
            }
        }
        
        visitingNodes[node] = 0;
        visitedNodes[node] = 1;
        stack.push_back(node);
        return false;
    }
};