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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (!headA || !headB) {
            return NULL;
        }
        
        int sizeA = 0, sizeB = 0;
        ListNode * cur = headA;
        
        while (cur) {
            cur = cur->next;
            sizeA++;
        }
        
        cur = headB;
        
        while (cur) {
            cur = cur->next;
            sizeB++;
        }
        
        int diff = abs(sizeA - sizeB);
        ListNode * cur1 = (sizeA >= sizeB) ? headA : headB;
        ListNode * cur2 = (sizeA < sizeB) ? headA : headB;
        
        for (int i = 0; i < diff; i++) {
            cur1 = cur1->next;
        }
        
        while (cur1 && cur2) {
            if (cur1 == cur2) {
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return NULL;
    }
};
