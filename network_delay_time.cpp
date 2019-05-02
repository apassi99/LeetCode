class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int result = 0;
        unordered_map<int, vector<pair<int,int>>> G;
        
        for (int i = 0; i < times.size(); i++) {
            int node1 = times[i][0];
            int node2 = times[i][1];
            int weight = times[i][2];
            
            if (G.find(node1) == G.end()) {
                vector<pair<int,int>> temp;
                G[node1] = temp;
            }
            
            G[node1].push_back(make_pair(node2, weight));
        }
        
        list<int> q;
        unordered_set<int> visitedNodes;
        unordered_map<int, int> shortestDistance;
        
        q.push_back(K);
        shortestDistance[K] = 0;
        
        while (!q.empty()) {
            
            int cur = q.back();
            q.pop_back();
            
            visitedNodes.insert(cur);
            
            vector<pair<int,int>> neighbors = G[cur];
            
            for (int i = 0; i < neighbors.size(); i++) {
                int neighborNode = neighbors[i].first;
                int weight       = neighbors[i].second;
                
                if (shortestDistance.find(neighborNode) != shortestDistance.end()) {
                    shortestDistance[neighborNode] = min(shortestDistance[neighborNode], weight +
                                                         shortestDistance[cur]);
                } else {
                    shortestDistance[neighborNode] = weight + shortestDistance[cur];
                }
            }
            
            int shortestDist = INT_MAX;
            int nextNode     = -1;
            
            for (int i = 1; i <= N; i++) {
                if (visitedNodes.find(i) == visitedNodes.end() &&
                    shortestDistance.find(i) != shortestDistance.end()) {
                    if (shortestDist > shortestDistance[i]) {
                        shortestDist = shortestDistance[i];
                        nextNode = i;
                    }
                }
            }
            
            if (nextNode != -1) {
                q.push_back(nextNode);
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (visitedNodes.find(i) == visitedNodes.end()) {
                return -1;
            } else {
                result = max(shortestDistance[i], result);
            }
        }
        
        return result;
    }
};