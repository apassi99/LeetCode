class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        list<int> s;
        vector<int> result;
        
        result.resize(T.size());
        
        for (int i = T.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && T[i] >= T[s.back()])
                s.pop_back();
            
            result[i] = s.empty() ? 0 : s.back() - i;
            s.push_back(i);
        }
        
        return result;
    }
};