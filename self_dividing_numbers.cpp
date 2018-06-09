class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i))
                result.push_back(i);
        }
        return result;
    }
    
private:
    
    bool isSelfDividing(int num) {
        string str = to_string(num);
        
        for (int i = 0; i < str.size(); i++) {
            int temp = str[i] - '0';
            if (temp == 0 || num % temp != 0)
                return false;
        }
        
        return true;
    }
};