typedef unordered_map<int, unordered_set<int>> Graph;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        Graph graph;
        vector<int> result;
        unordered_set<int> visitedNodes;
        unordered_set<int> visitingNodes;
        
        for (size_t idx = 0; idx < prerequisites.size(); idx++)
        {
            int course1 = prerequisites[idx][0];
            int course2 = prerequisites[idx][1];
            
            if (graph.find(course1) == graph.end())
            {
                unordered_set<int> temp;
                graph[course1] = temp;
            }
            
            graph[course1].insert(course2);
        }
        
        for (int i = 0; i < numCourses; i++)
        {
            bool dfsResult = dfs(graph, i, visitedNodes, visitingNodes, result);
            
            if (!dfsResult)
            {
                result.clear();
                return result;
            }
        }
        
        return result;
    }
    
private:
    
    bool dfs(Graph &graph, int currentNode,
             unordered_set<int> &visitedNodes, 
             unordered_set<int> &visitingNodes,
             vector<int> &result)
    {
        
        if (visitingNodes.find(currentNode) != visitingNodes.end())
        {
            return false;
        }
        
        if (visitedNodes.find(currentNode) != visitedNodes.end())
        {
            return true;
        }
        
        visitingNodes.insert(currentNode);
        
        // Visit neighbors
        unordered_set<int>::iterator it;
        for(it = graph[currentNode].begin(); it != graph[currentNode].end(); ++it)
        {
            bool dfsResult = dfs(graph, *it, visitedNodes, visitingNodes, result);
            
            if (!dfsResult)
                return false;
        }
        
        visitingNodes.erase(currentNode);
        visitedNodes.insert(currentNode);
        result.push_back(currentNode);
        
        return true;
    }
};