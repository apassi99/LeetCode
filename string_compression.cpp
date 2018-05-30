class Solution {
public:
    int compress(vector<char>& chars) {
        
        char prev = '\0';
        int count = 0;
        int idx = 0;
        
        for (int i = 0; i < chars.size(); i++) {
            if (prev != chars[i] || i == chars.size() - 1) {
                
                char cur = chars[i];
                count += (prev == cur) ? 1 : 0;

                if (count > 1) {
                    string temp = to_string(count);
                    for (int j = 0; j < temp.size(); j++) {
                        chars[idx] = temp[j];
                        idx++;
                    }
                } 

                if (prev != cur) {
                    chars[idx] = chars[i];
                    idx++;
                }
                
                count = 1;
            } else if (prev == chars[i]) {
                count++;
            }

            prev = chars[i];
        }
        
        return idx;
    }
};