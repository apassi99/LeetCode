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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (!head || n <= 0) {
            return head;
        }
        
        ListNode * first = head;
        ListNode * second = head;
        
        for (int i = 0; i < n; i++) {
            second = second->next;
            
            if (!second && i != n - 1) {
                return head;
            } else if (!second) {
                break;
            }
        }
        
        if (!second) {
            ListNode * newHead = head->next;
            delete head;
            return newHead;
        }
        
        while (second->next) {
            first = first->next;
            second = second->next;
        }
        
        ListNode * delNode = first->next;
        first->next = delNode->next;
        delete delNode;
        
        return head;
    }
};
