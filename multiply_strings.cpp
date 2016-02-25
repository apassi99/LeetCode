class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1.size() <= 0 || num2.size() <= 0) {
            return "";
        }
        
        if (num1.size() < num2.size()) {
            return multiply(num2, num1);
        }
        
        vector<list<char>> results;
        int cary = 0;
        
        for (int i = num2.size() - 1; i >= 0; i--) {
            
            list<char> str_result;
            cary = 0;
            
            for (int j = num1.size() - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                
                int r = (a * b) + cary;
                cary = r / 10;
                r = r % 10;
                
                str_result.push_front(r + '0');
            }
            
            results.push_back(str_result);
        }
        
        return add(&results);
        
    }
    
private:
    
    string add(vector<list<char>> *numbers) {
        
        list<char> sum;
        addHelper(numbers, 0, &sum);
        
        string result;
        
        for (int i = 0; i < sum.size(); i++) {
            result.push_back(sum[i]);
        }
        
        return result;
    }
    
    void addHelper(vector<list<char>> * v, int index, list<char> * currentSum) {
        if (i >= v->size()) {
            return;
        }
        
        list<char> num1 = (*v)[index];
        
        list<char> currentResult;
        
        int count = 0;
        int carry = 0;
        int num1size = num1.size();
        int curSumSize = currentSum->size();
            
        while (count < num1size || count < curSumSize) {
            int n1 = (count < num1size) ? num1[count] : 0;
            int n2 = (count < curSumSize) ? (*currentSum)[count] : 0;
                
            int r = n1 + n2 + cary;
            cary = r / 10;
            r = r % 10;
            
            if (count >= curSumSize) {
                currentSum->push_front(r + '0');
                
            } else {
                    (*currentSum)[count] = r + '0';
                }
                
                count++;
            }
        }
        
        addHelper(v, index+1, currentSum);
        
    }
    
    // 18  j
    // 2   i
};

// a * b = d // c = d / 10
