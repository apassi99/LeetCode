class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        if (n <= 0)
            return result;
        
        generateParenthesis(result, "(", n-1, n);
        
        return result;
    }
    
private:
    // cbn = closing brackets needed
    void generateParenthesis(vector<string> &result, string str, int n, int cbn) {
        
        if (n == 0) {
            for (int i = 0; i < cbn; i++) {
                str.append(")");
            }
            result.push_back(str);
            return;
        }
        
        string t1 = str;
        string t2 = str;
        
        t1.append("(");
        t2.append(")");
        
        generateParenthesis(result, t1, n-1, cbn);
        
        if (n < cbn)
            generateParenthesis(result, t2, n, cbn-1); // ( ( ) (
        
    }
};
