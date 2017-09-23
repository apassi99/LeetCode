class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        int minLen = 4;
        int maxLen = 12;
        vector<string> result;
        
        if (s.size() < minLen || s.size() > maxLen) {
            return result;
        }
        
        restoreIpAddrHelper(s, "", result, 0);
        return result;
    }
    
private:
    
    void restoreIpAddrHelper(string s, string ans,
                             vector<string> &result, int octNum) {
        
        if (s.size() == 0 && octNum == 4) {
            ans.pop_back();
            result.push_back(ans);
        }
        
        if ( (s.size() == 0 && octNum != 4) ||
             (s.size() > 0 && octNum == 4) ){
            return;
        }

        int count = (s.size() > 3) ? 3 : s.size();
        
        for (int i = 1; i <= count; i++) {
            string temp = s.substr(0, i);
            int number = atoi(temp.c_str());
            
            if (number > 255 || number < 0) {
                return;
            } else if (temp.size() > 1 && temp[0] == '0') {
                return;
            }
            
            string ans_temp = ans;
            ans_temp.append(temp);
            ans_temp.append(".");
            
            restoreIpAddrHelper(s.substr(i, s.size()), ans_temp, result, octNum+1);
        }
        
    }
};