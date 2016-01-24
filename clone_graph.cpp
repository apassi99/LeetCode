// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

// OJ's undirected graph serialization:
// Nodes are labeled uniquely.

// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if (!node)
            return node;
            
        map<UndirectedGraphNode *, UndirectedGraphNode *> oldToNewMap;
        
        UndirectedGraphNode * n = new UndirectedGraphNode(node->label);
        
        cloneGraphHelper(node, n, &oldToNewMap);

        return n;
        
    }
 
private:

    void cloneGraphHelper(  UndirectedGraphNode *oldNode, 
                            UndirectedGraphNode *newNode,
                            map<UndirectedGraphNode *, UndirectedGraphNode *> *oldToNewMap) {
        
        if (!oldNode || !newNode) {
            return;
        }
        
        // Already visited this node
        if ( contains(oldToNewMap, oldNode) ) {
            return;
        }
        
        (*oldToNewMap)[oldNode] = newNode;
        
        vector<UndirectedGraphNode *> oldNeighbors = oldNode->neighbors;
        
        for (int i = 0; i < oldNeighbors.size(); i++) {
        
            UndirectedGraphNode * o = oldNeighbors[i];
            UndirectedGraphNode * n =   ( contains(oldToNewMap, o) ) ? (*oldToNewMap)[o] :
                                        new UndirectedGraphNode(o->label);
            
            if (n != newNode) {
                newNode->neighbors.push_back(n);
            } else {
                n->neighbors.push_back(newNode);
            }
            
            cloneGraphHelper(o, n, oldToNewMap);
        }
    }
    
    bool contains(  map<UndirectedGraphNode *, UndirectedGraphNode *> *oldToNewMap, 
                    UndirectedGraphNode * oldNode) {
        
        try {
            oldToNewMap->at(oldNode);
            return true;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
};
