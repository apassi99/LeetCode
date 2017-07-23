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
    ListNode* swapPairs(ListNode* head) {
        
        if (!head || !head->next)
            return head;
        
        ListNode * first = head;
        ListNode * second = head->next;
        
        while (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
            first = second->next;
            second = (first) ? first->next : NULL;
        }
        
        return head;
    }
};
