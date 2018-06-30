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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result;

        
        ListNode * cur = root;
        ListNode * prev = NULL;
        int size = getSize(root);
        int itemsPerList = size / k;
        int extraItemsPerList = size % k;
        
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            if (count == 0) {
                result.push_back(cur);
                k--;
            }

            prev = cur;
            cur = cur->next;
            count++;
            
            int temp = (extraItemsPerList > 0) ? 1 : 0;
            
            if (count == itemsPerList + temp) {
                count = 0;
                extraItemsPerList--;
                prev->next = NULL;
            }
        }
        
        while (k > 0) {
            result.push_back(NULL);
            k--;
        }
        
        return result;
    }
    
    int getSize(ListNode * n) {
        int result = 0;
        while (n) {
            result++;
            n = n->next;
        }
        return result;
    }
};