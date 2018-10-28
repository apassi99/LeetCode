/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int maxSumCount = 0;
        unordered_map<int,int> freqMap;
        vector<int> result;
        
        findTreeSum(root, freqMap, maxSumCount);
        
        for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
            if (it->second == maxSumCount) {
                result.push_back(it->first);
            }
        }
        
        return result;
    }
    
private:
    
    int findTreeSum(TreeNode * root, unordered_map<int,int> &freqMap, int &maxSumCount) {
        
        if(!root)
            return 0;
        
        int leftSum = findTreeSum(root->left, freqMap, maxSumCount);
        int rightSum = findTreeSum(root->right, freqMap, maxSumCount);
        int rootSum = root->val + leftSum + rightSum;
        
        if (freqMap.find(rootSum) != freqMap.end()) {
            freqMap[rootSum]++;
        } else {
            freqMap[rootSum] = 1;
        }
        
        maxSumCount = max(maxSumCount, freqMap[rootSum]);
        return rootSum;
    }
};
