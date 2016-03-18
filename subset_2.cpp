class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        
        if (nums.size() <= 0) {
            return v;
        }
          
        sort(nums.begin(), nums.end());
        vector<int> curSubSet;
        printSubsetsHelper(&v, &curSubSet, &nums);
        
        v.push_back(curSubSet);
        
        return v;
    }
    
private:

    void printSubsetsHelper(vector<vector<int>> *v , vector<int> * curSubSet, vector<int> * bag) {
      
        while( bag->size() > 0) {
            
            vector<int> newBag(bag->begin(), bag->end());
            newBag.erase(newBag.begin());
        
            while (bag->size() > 1 && bag->at(0) == bag->at(1)) {
                bag->erase(bag->begin());
            }
            
            curSubSet->push_back( bag->at(0) );
            v->push_back(*curSubSet);
            printSubsetsHelper(v, curSubSet, &newBag);
            curSubSet->pop_back();
            
            bag->erase(bag->begin());
        
        }
    }
};
