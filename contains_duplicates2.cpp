#include <map>
#include <vector>
#include <iostream>

using std::map;
using std::vector;
using std::cout;
using std::endl;

static bool containsNearbyDuplicate(vector<int>& nums, int k);

// Given an array of integers and an integer k, 
// find out whether there are two distinct indices 
// i and j in the array such that nums[i] = nums[j] 
// and the difference between i and j is at most k.

int main() {

    int myints[] = {0, 1, 2, 3, 0};
    vector<int> list (myints, myints + sizeof(myints) / sizeof(int) );

    // Result True
    cout << containsNearbyDuplicate(list, 4) << endl;

    // Result False
    cout << containsNearbyDuplicate(list, 4) << endl;

    int myints1[] = {0, 1, 2, 3, 0, 4, 5, 2, 3};
    vector<int> list1 (myints1, myints1 + sizeof(myints1) / sizeof(int) );

    // Result False
    cout << containsNearbyDuplicate(list1, 3) << endl;

    // Result True
    cout << containsNearbyDuplicate(list1, 4) << endl;

    return 0;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {

    if (k <= 0)
        return false;

    if (k >= nums.size())
        k = nums.size() - 1;
            
    std::map<int, vector<int> > valToIndex;
        
    for (int i = 0; i < nums.size(); i++) {
        int val = nums[i];
        valToIndex[val].push_back(i);
        vector<int> list = valToIndex[val];
            
        if (list.size() > 1) {
            if (i - list[list.size()-2] <= k) {
                return true;
            }
        }
    }
        
    return false;
}