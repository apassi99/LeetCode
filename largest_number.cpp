class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        std::sort (nums.begin(), nums.end(), Solution::custom_sort);
        string result;
        
        for (int i = 0; i < nums.size(); i++) {
            result.append(std::to_string(nums[i]));
        }
        
        return result[0] == '0' ? "0" : result;
    }
    
private:
    
    static bool custom_sort(int a, int b) {
        string a_ = std::to_string(a);
        string b_ = std::to_string(b);
        
        string num1 = a_ + b_;
        string num2 = b_ + a_; 
        
        return num1 > num2;
    }
};