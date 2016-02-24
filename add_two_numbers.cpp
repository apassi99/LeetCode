// You are given two linked lists representing two non-negative numbers. 
// The digits are stored in reverse order and each of their nodes contain 
// a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int cary = 0;
        
        ListNode * cur1 = l1;
        ListNode * cur2 = l2;
        ListNode * cpy = new ListNode(0);
        ListNode * curN = cpy;
        
        while (cur1 || cur2 || cary > 0) {
            
            int temp1 = (cur1) ? cur1->val : 0;
            int temp2 = (cur2) ? cur2->val : 0;
            
            curN->next = new ListNode((temp1 + temp2 + cary) % 10 );
            cary = (temp1 + temp2 + cary) / 10;
            curN = curN->next;
            cur1 = (cur1) ? cur1->next : NULL;
            cur2 = (cur2) ? cur2->next : NULL;
        }
        
        curN = cpy->next;
        delete cpy;
        return curN;
    }
};
