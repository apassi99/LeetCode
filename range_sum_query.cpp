class NumArray {
public:
    NumArray(vector<int> &nums) {
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        if (i > j | j >= nums.size()) {
            return 0;
        }
        
        return findSum(j) - findSum(i-1);
    }
    
    int findSum(int i) {
        if (i >= nums.size() | i < 0)
            return 0;
        try {
            return mymap.at(i);
        } catch (const std::out_of_range& oor) {
            int sum = nums[i] + findSum(i-1);
            mymap[i] = sum;
            return sum;
        }
    }
private:
    vector<int> nums;
    map<int, int> mymap;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
