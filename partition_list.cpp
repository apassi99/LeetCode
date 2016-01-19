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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;
            
        ListNode * high = new ListNode(0);
        ListNode * low = new ListNode(0);
        
        ListNode * curHigh = high;
        ListNode * curLow = low;
        
        ListNode * cur = head;
        
        while (cur) {
            
            ListNode * next = cur->next;
            
            if (cur->val >= x) {
                curHigh->next = cur;
                curHigh = curHigh->next;
            } else {
                curLow->next = cur;
                curLow = curLow->next;
            }
            
            cur->next = NULL;
            cur = next;
        }
        
        while (curLow->next) {
            curLow = curLow->next;
        }
        
        curLow->next = high->next;
        
        ListNode * newHead = low->next;
        free(low);
        free(high);
        
        return newHead;
    }
};
