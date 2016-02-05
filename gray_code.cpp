// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. // A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.
//
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//
// Assuming n < 32

class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector <int> l;
        
        if (n < 0)
            return l;
        
        grayCodeHelper(&l, n);
        return l;
    }

private:

    void grayCodeHelper(vector<int> *v, int n) {
        
        if (n == 0) {
            v->push_back(0);
            return;
        }
        
        grayCodeHelper(v, n - 1);
        
        int bitVal = 1 << (n - 1);
        int size = v->size() - 1;
        
        for (int i = size; i >= 0; i--) {
            int newVal = (*v)[i] | bitVal;
            v->push_back(newVal);
        }
        
    }
};
