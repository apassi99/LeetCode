class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        vector<int> result;
        int numPeople = quiet.size();
        
        if (richer.empty() || richer[0].empty() || quiet.empty()) {
            for (int i = 0; i < numPeople; i++) {
                result.push_back(i);
            }
            return result;
        }
        
        /* Build graph matrix. */
        vector<vector<int> *> * graphMatrix = new vector<vector<int>*>();
        
        for (int i = 0; i < numPeople; i++) {
            vector<int> * temp = new vector<int>();
            for (int j = 0; j < numPeople; j++)
                temp->push_back(0);
            graphMatrix->push_back(temp);
        }
        
        for (int i = 0; i < richer.size(); i++) {
            int x = richer[i][0];
            int y = richer[i][1];
            (*(*graphMatrix)[y])[x] = 1;
        }
        
        for (int i = 0; i < numPeople; i++) {
            int ans = quiet[i];
            int person = i;
            dfsHelper(graphMatrix, i, quiet, &ans, &person);
            result.push_back(person);
            memoTable[i] = make_pair(ans, person);
        }
        
        
        /* Deallocate graphMatrix memory*/
        for (int i = 0; i < numPeople; i++)
            delete (*graphMatrix)[i];
        delete graphMatrix;
        
        
        return result;
    }
    
private:
    
    void dfsHelper(vector<vector<int> *> * G, int node, vector<int>& quiet, int * ans, int *person) {
        
        vector<int> * neighbors = (*G)[node];
        
        if (memoTable.find(node) != memoTable.end()) {
            if (*ans > memoTable[node].first) {
                *ans = memoTable[node].first;
                *person = memoTable[node].second;
            }
            return;
        }
        
        for (int i = 0; i < neighbors->size(); i++) {
            if (i != node && (*neighbors)[i] == 1) {
                if (*ans > quiet[i]) {
                    *ans = quiet[i];
                    *person = i;
                }
                dfsHelper(G, i, quiet, ans, person);
            }
        }
    }
    
    unordered_map<int, pair<int,int>> memoTable;
    
};