class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

        bool result = true;
        unordered_map<int, int> * nodeGroup = new unordered_map<int, int>();
        
        /* Build graph matrix. */
        vector<vector<int>*> * G = new vector<vector<int>*>();
        
        for (int i = 0; i < N; i++ ){
            vector<int> * temp = new vector<int>();
            for (int j = 0; j < N; j++) {
                temp->push_back(0);
            }
            G->push_back(temp);
        }
        
        for (int i = 0; i < dislikes.size(); i++) {
            int x = dislikes[i][0] - 1;
            int y = dislikes[i][1] - 1;
            (*(*G)[y])[x] = 1;
            (*(*G)[x])[y] = 1;
        }
        
        for (int i = 0; i < N; i++) {
            if (nodeGroup->find(i) == nodeGroup->end())
                if (!dfs(G, i, 0, nodeGroup)) {
                    result = false;
                    break;
                }
        }

        /* Deallocate graphMatrix memory*/
        for (int i = 0; i < N; i++)
            delete (*G)[i];
        delete G;
        delete nodeGroup;
        
        return result;
    }
    
private:
    
    bool dfs(vector<vector<int> *> * G, int node, int color, unordered_map<int, int> *group) {

        if (group->find(node) != group->end())
            return (*group)[node] == color;
        
        (*group)[node] = color;
        
        for (int i = 0; i < G->size(); i++) {
            if (i != node && (*(*G)[node])[i] == 1) {
                if (!dfs(G, i, 1 - color, group)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};