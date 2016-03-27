class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        unordered_set<GraphNode *> unvisted_nodes;
        unordered_set<GraphNode *> visiting_nodes;
        unordered_set<GraphNode *> visited_nodes;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            pair<int, int> p = prerequisites[i];
            
            if ( !contains(p.second) ) {
                GraphNode * n = new GraphNode;
                n->courseNum = p.second;
                nodes[p.second] = n;
                unvisted_nodes.insert(n);
            }
            
            if ( !contains(p.first) ) {
                GraphNode * v = new GraphNode;
                v->courseNum = p.first;
                nodes[p.first] = v;
                unvisted_nodes.insert(v);
            }
            
            addNodeToList( nodes[p.second], nodes[p.first]);
        }
        
        bool value = true;
        
        
        while ( unvisted_nodes.size() > 0 ) {
            
            auto local_it = unvisted_nodes.begin();
            
            if ( hasCycles( *local_it, &unvisted_nodes, &visiting_nodes, &visited_nodes) ) {
                value = false;
                break;
            }
            
            ++local_it;
        }
        
        for (std::map<int, GraphNode *>::iterator it= nodes.begin(); it!= nodes.end(); ++it) {
            delete it->second;
        }
        
        return value;

    }
    
private:

    typedef struct node {
        vector<struct node *> adjList;
        int courseNum;
    } GraphNode;
    
    map<int, GraphNode *> nodes;
    
    void addNodeToList(GraphNode * n, GraphNode * v) {
        n->adjList.push_back(v);
    }
    
    bool contains(int value) {
        try {
            nodes.at(value);
            return true;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
    
    void moveNode(GraphNode * n, unordered_set<GraphNode *> * set1, unordered_set<GraphNode *> * set2) {
        set1->erase(n);
        set2->insert(n);
    }
    
    bool hasCycles(GraphNode * n, unordered_set<GraphNode *> * unvisited_nodes, 
                                  unordered_set<GraphNode *> * visited_nodes, 
                                  unordered_set<GraphNode *> * visiting_nodes) {
        
        // Have I already visited this node
        if (visited_nodes->find(n) != visited_nodes->end()) {
            return true;
        }
        
        moveNode(n, unvisited_nodes, visiting_nodes);

        
        for (int i = 0; i < n->adjList.size(); i++) {
            
            GraphNode * temp = n->adjList[i];
            
            if ( visiting_nodes->find(temp) != visiting_nodes->end()) {
                return true;
            }
            
            else if ( visited_nodes->find(temp) != visited_nodes->end()) {
                continue;
            }
            
            else if ( hasCycles(temp, unvisited_nodes, visited_nodes, visiting_nodes)) {
                return true;
            }
        }
        
        moveNode(n, visiting_nodes, visited_nodes);
        
        return false;
    }
    
};