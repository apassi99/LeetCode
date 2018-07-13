/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        list<TreeNode *> l;
        string result;
        
        if (root) l.push_back(root);
        
        while (!l.empty()) {
            
            int size = l.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode * n = l.front();
                l.pop_front();
                
                if (n) {
                    result.append(to_string(n->val) + ",");
                    l.push_back(n->left);
                    l.push_back(n->right);
                } else {
                    result.append("n,");
                }
            }
        }
        
        if (!result.empty())
            result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        TreeNode * root = NULL;
        
        int idx = 0;
        string value = "";
        
        list<TreeNode *> l;
        
        
        while (idx < data.size()) {
            
            getNextVal(data, idx, value);
            
            if (l.empty()) {
                root = new TreeNode(stoi(value));
                l.push_back(root);
            } else {
                TreeNode * n = l.front();
                l.pop_front();
                
                while (!n && !l.empty()) {
                    n = l.front();
                    l.pop_front();
                }
                
                if (!n) {
                    break;
                }
                
                if (value != "n" && value != "") {
                    n->left = new TreeNode(stoi(value));
                } else {
                    n->left = NULL;
                }
                
                l.push_back(n->left);
                
                getNextVal(data, idx, value);
                
                if (value != "n" && value != "") {
                    n->right = new TreeNode(stoi(value));
                } else {
                    n->right = NULL;
                }
                
                l.push_back(n->right);
                
            }
        }
        
        return root;
    }
    
private:
    
    void getNextVal(string &data, int &idx, string &value) {
        
        value = "";

        if (idx >= data.size()) 
            return;
        
        if (data[idx] == 'n') {
            value = "n";
            idx += 2;
            return;
        }
        
        while (idx < data.size() && data[idx] != ',') {
            value = value + data[idx];
            idx++;
        }
        idx++;

    }
};

// 1, 2, null, 

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));