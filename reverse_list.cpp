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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode * cur1 = head;
        ListNode * cur2 = head->next;
        ListNode * cur3 = cur2->next;
        
        cur1->next = NULL;
        
        while (cur2) {
            cur2->next = cur1;
            cur1 = cur2;
            cur2 = cur3;
            cur3 = (cur3 != NULL) ? cur3->next : cur3;
        }
        
        return cur1;
    }
};
