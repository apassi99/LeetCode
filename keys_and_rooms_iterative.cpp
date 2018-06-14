class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int N = rooms.size();
        set<int> visitedNodes;
        set<int> visitingNodes;
        bool result = N > 0;
        
        list<int> q;
        
        if (rooms.size() > 0)  {
            q.push_back(0);
            visitingNodes.insert(0);
        }
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                
                int node = q.front();
                
                for (int j = 0; j < rooms[node].size(); j++) {
                    if (visitingNodes.find(rooms[node][j]) == visitingNodes.end() &&
                        visitedNodes.find(rooms[node][j]) == visitedNodes.end()) {
                        q.push_back(rooms[node][j]);
                        visitingNodes.insert(rooms[node][j]);
                    }
                }

                visitingNodes.erase(node);
                visitedNodes.insert(node);
                q.pop_front();
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (visitedNodes.find(i) == visitedNodes.end()) {
                return false;
            }
        }
        
        return result;
    }
};