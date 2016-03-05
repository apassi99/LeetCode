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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n)
            return head;
            
        ListNode * prev = NULL;
        ListNode * start = NULL;
        ListNode * cur1 = head;
        ListNode * cur2 = head->next;
        
        int count = 1;
        while (count < m) {
            prev = cur1;
            cur1 = cur1->next;
            count++;
        }
        
        start = cur1;
        cur2 = cur1->next;
        ListNode * cur3 = cur2->next;
        
        while (count < n) {
            cur2->next = cur1;
            cur1 = cur2;
            cur2 = cur3;
            if (cur3) cur3 = cur3->next;
            count++;
        }
        
        start->next = cur2;
        if (prev) prev->next = cur1;
        
        return (prev) ? head : cur1;
        
    }
};
