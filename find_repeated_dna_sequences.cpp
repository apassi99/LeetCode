class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        
        if (s.size() < 10) {
            return result;
        }
        
        map<string, int> occurrences;
        
        for (int i = 0; i <= s.size() - 10; i++) {
            string temp = s.substr(i,10);

            if (occurrences[temp] == 1) {
                result.push_back(temp);
            }
            
            occurrences[temp] += 1;
        }
        
        return result;
    }
};