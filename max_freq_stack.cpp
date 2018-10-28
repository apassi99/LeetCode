class FreqStack {
public:
    FreqStack() {

    }
    
    void push(int x) {

        int newFrequency = occurenceMap[x] + 1;
        occurenceMap[x] = newFrequency;
        
        if (newFrequency > stackData.size()) {
            vector<int> * temp = new vector<int>();
            temp->push_back(x);
            stackData.push_back(temp);
        } else {
            stackData[newFrequency - 1]->push_back(x);
        }

    }
    
    int pop() {
        
        int result = stackData.back()->back();
        occurenceMap[result] = occurenceMap[result] - 1;
        stackData.back()->pop_back();
        
        if (stackData.back()->empty()) {
            vector<int> * lastVector = stackData.back();
            stackData.pop_back();
            delete lastVector;
        }
        
        return result;
    }
    
private:

    vector<vector<int> *> stackData;
    unordered_map<int, int> occurenceMap;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
