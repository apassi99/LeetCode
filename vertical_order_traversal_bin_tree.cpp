
void verticalOrderTraversalHelper(TreeNode* n, int l, int d, int &low_line, int &max_line,
                                  unordered_map<int, map<int, vector<int>>> &levelAndDepthMap) {
    
    if (!n)
        return;
    
    low_line = min(low_line, l);
    max_line = max(max_line, l);
    
    if (levelAndDepthMap.find(l) == levelAndDepthMap.end()) {
        map<int,vector<int>> temp;
        levelAndDepthMap[l] = temp;
    }
    
    if (levelAndDepthMap[l].find(d) == levelAndDepthMap[l].end()) {
        vector<int> temp;
        levelAndDepthMap[l][d] = temp;
    }

    levelAndDepthMap[l][d].push_back(n->val);

    verticalOrderTraversalHelper(n->left, l-1, d+1, low_line, max_line, levelAndDepthMap);
    verticalOrderTraversalHelper(n->right, l+1, d+1, low_line, max_line, levelAndDepthMap);
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    int low_line = INT_MAX;
    int max_line = INT_MIN;
    vector<vector<int>> result;
    unordered_map<int, map<int,vector<int>>> levelAndDepthMap;
    
    verticalOrderTraversalHelper(A, 0, 0, low_line, max_line, levelAndDepthMap);
    
    if (low_line == INT_MAX || max_line == INT_MIN) {
        return result;
    }
    
    for (int i = low_line; i <= max_line; i++) {
        map<int,vector<int>> depthMap = levelAndDepthMap[i];
        vector<int> temp;
        
        for (map<int,vector<int>>::iterator it = depthMap.begin(); it!= depthMap.end(); ++it) {
            for (int j = 0; j < it->second.size(); j++) {
                temp.push_back(it->second[j]);
            }
        }

        result.push_back(temp);
    }

    return result;
}