class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            m_Sum.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        int temp = (i == 0) ? 0 : m_Sum[i-1];
        return m_Sum[j] - temp;
    }
    
private:
    
    vector<int> m_Sum;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */