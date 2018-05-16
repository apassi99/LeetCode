class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> p;
        p.first = start;
        p.second = end;
        
        if (container.find(p) != container.end()) {
            return false;
        }
        
        container.insert(p);
        
        return true;
    }
    
private:
    
    struct IntervalCmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){return a.second <= b.first; }
    };
    
    set<pair<int,int>, IntervalCmp> container;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */