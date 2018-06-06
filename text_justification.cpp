class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result;
        int startidx = 0, curWidth = 0, curLenNeeded = 0, numWords = 0,
            spacesNeeded = 0, spacePerWord = 0, extraSpacePerWord = 0;
        
        for (int i = 0; i <= words.size(); i++) {
            
            curLenNeeded = curWidth + words[i].size() + (i - startidx);
            
            if (curLenNeeded > maxWidth || i == words.size()) {
                
                numWords = (i - 1 - startidx);
                spacesNeeded = maxWidth - curWidth;

                spacePerWord = (numWords >= 1) ? spacesNeeded / numWords : 0;
                spacePerWord = (numWords >= 1 && i == words.size()) ? 1 : spacePerWord;
                extraSpacePerWord = (numWords >= 1 && i != words.size()) ? spacesNeeded % numWords : 0;

                result.push_back("");

                for (int j = startidx; j < i; j++) {

                    if (j == i-1 && i != words.size()) {
                        spacePerWord = 0;
                        extraSpacePerWord = 0;
                    }

                    result[result.size()-1].append(words[j] + getNSpaces(spacePerWord));

                    if (extraSpacePerWord > 0) {
                        result[result.size()-1].append(getNSpaces(1));
                        extraSpacePerWord--;
                        spacesNeeded--;
                    }
                    
                    spacesNeeded = spacesNeeded - spacePerWord;
                    spacePerWord = (spacesNeeded <= 0) ? 0 : spacePerWord;
                    extraSpacePerWord = (spacesNeeded <= 0) ? 0 : extraSpacePerWord;
                }

                result[result.size()-1].append(getNSpaces(spacesNeeded));

                startidx = i;
                curWidth = 0;
            }
            curWidth += words[i].size();
        }
        return result;
    }
    
private:
    
    string getNSpaces(int n) {
        
        string str = "";
        
        while (n > 0) {
            str += " ";
            n--;
        }
        
        return str;
    }
};
