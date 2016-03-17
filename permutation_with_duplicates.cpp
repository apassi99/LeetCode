class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> l;

        sort(nums.begin(), nums.end());
        permuteUniqueHelper(&v, &l, &nums);

        return v;
    }
    
private:

    void permuteUniqueHelper(vector<vector<int>> * v, vector<int> * cur, vector<int> * bag) {
        
        if (bag->size() == 0) {
            v->push_back(*cur);
            return;
        }
        
        vector<int> nums(bag->begin(), bag->end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (i != 0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            vector<int> n(nums.begin(),nums.end());
            
            n.erase (n.begin()+i);
            
            cur->push_back(nums[i]);
            permuteUniqueHelper(v, cur, &n);
            cur->pop_back();
        }
    }
};
