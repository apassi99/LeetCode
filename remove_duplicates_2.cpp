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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode * cpy = new ListNode(0);
        cpy->next = head;
        
        ListNode * cur = cpy;
        
        while (cur->next && cur->next->next) {
            int temp = cur->next->next->val;
            
            if (temp == cur->next->val) {
                while (cur->next && temp == cur->next->val) {
                    ListNode * temp = cur->next;
                    delete temp;
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        
        cur = cpy->next;
        delete cpy;
        return cur;
    }
};
