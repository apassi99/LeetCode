class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() <= 1) {
            return s.size();
        }

        int result = 0, idx = 0, count = 0, lastIdx = -1;
        map<char, int> indexMap;

        while (idx < s.size()) {
            if (indexMap.find(s[idx]) != indexMap.end()) {
    
                int temp = (indexMap[s[idx]] > lastIdx) ? indexMap[s[idx]] : lastIdx;
                count = idx - temp;
                result = max(result, count);

                if (lastIdx < indexMap[s[idx]])
                    lastIdx = indexMap[s[idx]];

            } else {
                count++;
                result = max(result, count);
            }

            indexMap[s[idx]] = idx;
            idx++;
        }

        return result;
    }
};