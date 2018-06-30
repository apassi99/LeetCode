/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int result = 0;
        ListNode * cur = head;
        ListNode * prev = NULL;
        set<int> setG;
        bool flag = true;
        
        for (int i = 0; i < G.size(); i++) {
            setG.insert(G[i]);
        }
        
        while (cur) {
            if (setG.find(cur->val) != setG.end()) {
                if (!prev || setG.find(prev->val) == setG.end())
                    result++;
            }
            prev = cur;
            cur = cur->next;
        }
        
        return result;
    }
};