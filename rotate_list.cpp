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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k <= 0) {
            return head;
        }
        
        int size = 0;
        
        ListNode * cur = head;
        ListNode * tail = NULL;
        ListNode * newHead = cur;
        ListNode * prevNewHead = cur;
        
        while (cur) {
            tail = cur;
            cur = cur->next;
            prevNewHead = newHead;
            newHead = (size >= k) ? newHead->next : newHead;
            size++;
        }
        
        cout << newHead->val << endl;
        
        if (k % size == 0) {
            return head;
        }
        
        if (k > size) {
            newHead = head;
            k = k % size;
            cout << k << endl;
            for (int i = 0; i < size - k; i++) {
                prevNewHead = newHead;
                newHead = newHead->next;
            }
            
            cout << newHead->val << endl;
        }
        
        prevNewHead->next = NULL;
        
        tail->next = head;
        return newHead;
    }
};
