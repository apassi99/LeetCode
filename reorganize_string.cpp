class Solution {
public:
    string reorganizeString(string S) {
        
        int occurenceMap [26];
        int len = S.size();
        string result = "";
        
        memset(occurenceMap, 0, 26*sizeof(int));
        
        for (int i = 0; i < S.size(); i++) {
            occurenceMap[S[i] -'a'] += 1;
        }

        char cur = '*';

        for (int i = 0; i < len; i++) {

            char newCur = getNextChar(occurenceMap, cur);

            if (newCur == '*') {
                return "";
            }

            result += newCur;
            cur = newCur;
        }
        
        return result;
    }
    
private:
    
    char getNextChar(int *occurenceMap, char cur) {
        
        int index = cur - 'a';
        char returnChar = '*';
        int maxOcc = 0, maxIndex = -1;
        
        for (int i = 0; i < 26; i++) {
            if (i == index) {
                continue;
            }
            
            if (occurenceMap[i] > maxOcc) {
                maxOcc = occurenceMap[i];
                maxIndex = i;
            }
        }
        
        if (maxIndex != -1) {
            occurenceMap[maxIndex]--;
            returnChar = 'a' + maxIndex;
        }
        
        return returnChar;
    }
};