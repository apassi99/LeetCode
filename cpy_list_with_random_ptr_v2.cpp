/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return head;
        }
        
        RandomListNode * curOld = head;
        RandomListNode * curNew = NULL;
        
        while ( curOld ) {
            curNew = new RandomListNode(curOld->label);
            curNew->next = curOld->next;
            curOld->next = curNew;
            curOld = curNew->next;
        }
        
        curOld = head;
        RandomListNode * newHead = curOld->next;
        
        while ( curOld ) {
            curNew = curOld->next;
            curNew->random = (curOld->random) ? curOld->random->next : NULL;
            curOld = curNew->next;
        }
        
        curOld = head;
        
        while ( curOld ) {
            curNew = curOld->next;
            curOld->next = curNew->next;
            curNew->next = ( curNew->next ) ? curNew->next->next : NULL;
            curOld = curOld->next;
        }
        
        return newHead;
    }
};
