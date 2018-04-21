class Solution {
public:
    vector<int> partitionLabels(string S) {

        int i = 0;
        int len = S.size();
        vector<int> result;
        map<char, pair<int, int>> charIndexMap;
        
        for (i = 0; i < len; i++) {
            if (charIndexMap.find(S[i]) != charIndexMap.end()) {
                charIndexMap[S[i]].second = i;
            } else {
                pair<int, int> p;
                p.first = i;
                p.second = -1;
                charIndexMap[S[i]] = p;
            }
        }
        
        i = 0;

        while (i < len) {
            int i2 = charIndexMap[S[i]].second;
            
            if (i2 == -1) {
                result.push_back(1);
                i++;
                continue;
            }
            
            result.push_back(i2 - charIndexMap[S[i]].first + 1);
            i = i2+1;
            
            for (int idx = i2+1; idx < len; idx++) {
                if (charIndexMap[S[idx]].first < i2) {
                    result[result.size()-1] += idx - i2;
                    i2 = idx;
                    i = idx+1;
                }
            }
        }
        
        return result;
    }
};
