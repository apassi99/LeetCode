// Forward declaration of the knows API.
bool knows(int a, int b);

#include <list>

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        
        if (n <= 1) {
            return 0;
        }
        
        list<int> lst;

        for (int i = 0; i < n; i++) {
            lst.push_back(i);
        }
        
        int A = lst.front();
        int B = lst.back();
        
        while (lst.size() > 1) {
            if (knows(A, B)) {
                lst.pop_front();
                A = lst.front();
            } else {
                lst.pop_back();
                B = lst.back();
            }
        }
        
        A = lst.front();
        
        for (int i = 0; i < n; i++) {
            if (i != A && (knows(A, i) || !knows(i, A))) {
                return -1;
            } 
        }
        
        return A;
    }
};