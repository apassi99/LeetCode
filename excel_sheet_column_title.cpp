class Solution {
public:
    string convertToTitle(int n) {
        if (n < 1) {
            return "";
        }
        
        string str;
        
        while (n > 0) {
            char temp = ( (n - 1) % 26 ) + 'A';
            n = (n - 1) / 26;
            str.push_back(temp);
        }
        
        reverse(str);
        return str;
    }
    
private:

    
    void reverse(string &s) {
        
        int i1 = 0;
        int i2 = s.size() - 1;
        
        while (i1 < i2) {
            char temp = s[i1];
            s[i1] = s[i2];
            s[i2] = temp;
            i1++;
            i2--;
        }
    }
};
