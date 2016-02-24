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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
            
        map<int, ListNode*> indexToNode;
        
        ListNode * cur = head;
        
        int count = 0;
        
        while (cur) {
            indexToNode[count] = cur;
            ListNode * temp = cur;
            cur = cur->next;
            temp->next = NULL;
            count++;
        }
        
        int last = count - 1;
        
        for (int i = 0; i < count / 2; i++) {
            indexToNode[i]->next = indexToNode[last];
            indexToNode[last]->next = indexToNode[i+1];
            last--;
        }
        
        if (count % 2 == 0)
            indexToNode[last+1]->next = NULL;
        else
            indexToNode[last]->next = NULL;
    }
};
