#include <map>

using std::map;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (!head || !head->next || k <= 1)
            return head;
        
        map<int, int> * listMap = new map<int, int>();
        
        int size = 0;
        ListNode * cur = head;
        
        while (cur) {
            (*listMap)[size] = cur->val;
            cur = cur->next;
            size++;
        }
        
        cur = head;
        
        
        for (int i = 0; i + k - 1 < size; i = i + k) {
            for (int j = i+k; j > i; j--) {
                cur->val = (*listMap)[j-1];
                cur = cur->next;
                if (!cur) {
                    delete listMap;
                    return head;
                }
            }
        }
        
        delete listMap;
        return head;
    }
};
