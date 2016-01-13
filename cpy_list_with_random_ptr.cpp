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
     
        if (head == NULL)
            return head;
        
        map<RandomListNode*, RandomListNode*> nodeMap;
        
        RandomListNode * curOld = head;
        RandomListNode * newHead = new RandomListNode(curOld->label);
        RandomListNode * curNew = newHead;
        
        while ( curOld ) {
            nodeMap[curOld] = curNew;
            curNew->next = ( curOld->next ) ? new RandomListNode(curOld->next->label) : NULL;
            curNew = curNew->next;
            curOld = curOld->next;
        }
        
        curOld = head;
        curNew = newHead;
        
        while ( curOld ) {
            curNew->random = (curOld->random) ? nodeMap[curOld->random] : NULL;
            curNew = curNew->next;
            curOld = curOld->next;
        }
        
        return newHead;
    }
};
