// Given a singly linked list, group all odd nodes together followed by 
// the even nodes. Please note here we are talking about the
// node number and not the value in the nodes.
//
// You should try to do it in place. The program should run in 
// O(1) space complexity and O(nodes) time complexity.

// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.

// Note:
// The relative order inside both the even and odd groups should remain as it was in the input. 
// The first node is considered odd, the second node even and so on ...

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
    ListNode* oddEvenList(ListNode* head) {
        
        if (!head || !head->next)
            return head;
        
        ListNode * odd = head;
        ListNode * even = head->next;
        
        ListNode * cur1 = odd;
        ListNode * cur2 = even;
        ListNode * oddLast = cur1;
        
        // 1 -> 2 -> 3 -> 4 -> 5
        
        while(cur1 && cur2) {
            cur1->next = cur2->next;
            cur2->next = (cur2->next != NULL) ? cur2->next->next : NULL;
            oddLast = (cur1->next != NULL) ? cur1->next : cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        oddLast->next = even;
        return odd;
    }
};
