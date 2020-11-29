class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        
        
        m_calendarData[start]++;
        m_calendarData[end]--;
        
        int result   = 0;
        int bookings = 0;
        
        map<int,int>::iterator it;
        for (it = m_calendarData.begin(); it != m_calendarData.end(); it++)
        {
            bookings += it->second;
            result = max(bookings, result);
        }
        
        return result;
    }
    
private:
    
    map<int,int> m_calendarData;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */