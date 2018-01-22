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
    bool hasCycle(ListNode *head) {
        
        if (!head || !head->next)
            return false;
        
        ListNode * cur1 = head;
        ListNode * cur2 = head->next;
        
        while (cur1 && cur2) {
            if (cur1 == cur2) {
                return true;
            }
            
            cur1 = cur1->next;
            cur2 = (cur2->next) ? cur2->next->next : NULL;
        }
        
        return false;
    }
};