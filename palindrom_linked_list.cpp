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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        
        ListNode * cur = head;
        ListNode * cur2 = head;
        
        while (cur2 && cur2->next) {
            cur = cur->next;
            cur2 = cur2->next->next;
        } // 1 -> 3 -> 3 -> 1 -> 4
        
        ListNode ** mid = &cur;
        bool isOdd = (cur2 != NULL);
        
        return isPalindromeHelper(head, mid, isOdd);
    
    }
    
    bool isPalindromeHelper(ListNode * head, ListNode ** mid, bool isOdd) {
        
        
        if (isOdd) {
            if (head != *mid) {
                bool val = isPalindromeHelper(head->next, mid, isOdd);
            
                if (!val)
                    return val;
            }
        }
        
        else {
            if (head->next != *mid) {
                bool val = isPalindromeHelper(head->next, mid, isOdd);

                if (!val)
                    return val;
            }
        }
        
        // head == mid
        ListNode * mid_temp = *mid;
        
        if (head->val != mid_temp->val) {
            return false;
        }
        
        mid_temp = mid_temp->next;
        *mid = mid_temp;
        
        return true;
        
    }
};
