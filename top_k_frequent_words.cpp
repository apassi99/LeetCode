class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> wordFrequencyMap;
        vector<pair<int, const string*>> freqValueList;
        vector<string> result;
        
        // Build frequency map
        for (int i = 0; i < words.size(); i++) {
            wordFrequencyMap[words[i]]++;
        }

        // Build frequency value list
        typedef map<string, int>::iterator it_type;
        for (it_type iterator = wordFrequencyMap.begin(); iterator != wordFrequencyMap.end(); iterator++) {
            pair<int, const string*> p;
            p.first = iterator->second;
            p.second = &(iterator->first);
            freqValueList.push_back(p);
        }

        // Sort the frequency list
        sort(freqValueList.begin(), freqValueList.end(), sort_list);

        for (int i = 0; i < k; i++) {
            result.push_back(*(freqValueList[i].second));
        }

        return result;
    }
    
private:
    
    static bool sort_list(pair<int, const string*> p1, pair<int, const string*> p2) {
        
        if (p1.first > p2.first) {
            return true;
        } else if (p1.first < p2.first) {
            return false;
        } else {
            return (p1.second->compare(*(p2.second)) < 0);
        }
    }
};