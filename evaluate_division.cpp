class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
                                vector<double>& values, vector<pair<string, string>> queries) {
        
        vector<double> result;
        unordered_set<string> visitingNodes;
        unordered_map<string, unordered_map<string, double>> G;
        
        for (int i = 0; i < equations.size(); i++) {
            G[equations[i].first][equations[i].second] = values[i];
            G[equations[i].second][equations[i].first] = 1 / values[i];
        }
        
        for (int i = 0; i < queries.size(); i++) {
            visitingNodes.clear();
            
            if (queries[i].first != queries[i].second) {
                bool found = dfs(G, queries[i].first, queries[i].second, visitingNodes, result, 1.0);
                if (!found)
                    result.push_back(-1.0);
            } else {
                if (G.find(queries[i].first) != G.end())
                    result.push_back(1.0);
                else
                    result.push_back(-1.0);
            }
        }
        
        return result;
    }
    
private:
    
    bool dfs(unordered_map<string, unordered_map<string, double>> &G, const string &node, string &target,
             unordered_set<string> &visitingNode, vector<double> &result, double cur) {
        
        if (visitingNode.find(node) != visitingNode.end()) {
            return false;
        }
        
        if (node == target) {
            result.push_back(cur);
            return true;
        }
        
        visitingNode.insert(node);
        
        for (auto it = G[node].begin(); it != G[node].end(); ++it) {
            if (dfs(G, it->first, target, visitingNode, result, cur * it->second)) {
                return true;
            }
        }
        
        visitingNode.erase(node);
        return false;
    }
};