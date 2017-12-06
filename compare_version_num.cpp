class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i = 0, j = 0;
        int n1, n2;
        vector<int> v1, v2;
        
        decodeStr(version1, v1);
        decodeStr(version2, v2);
        
        while (i < v1.size() || j < v2.size()) {
            
            n1 = (i >= v1.size() ) ? 0 : v1[i];
            n2 = (j >= v2.size() ) ? 0 : v2[j];
            
            if (n1 < n2) {
                return -1;
            } else if (n1 > n2) {
                return 1;
            } else {
                i++;
                j++;
            }
        }
        
        return 0;
    }
    
private:
    
    void decodeStr(string str, vector<int> &version) {
        
        int i = 0, num = 0;

        while (i < str.size()) {

            if (str[i] == '.') {
                version.push_back(num);
                num = 0;
            } else {
                num = (num * 10) + (str[i] - '0');
                if (i == str.size() - 1)
                    version.push_back(num);
            }
            
            i++;
        }
    }
};