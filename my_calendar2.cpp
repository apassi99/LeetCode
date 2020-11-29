class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        // Increment events at start time (++)
        m_calendarData[start]++;
        
        // Decrement events at end time (--)
        m_calendarData[end]--;
        
        // variable used to track number of bookings made
        int booked = 0;
        
        // Iterate through times (start/end) in ascending order
        map<int,int>::iterator it;
        for (it = m_calendarData.begin(); it != m_calendarData.end(); it++)
        {
            // Sum up counts of start and end times.
            // Start times will increase booked variable
            // End times will decrese it.
            booked += it->second;
            
            // 3 booked events detected. We are
            // overbooked cancel current booking
            if (booked == 3)
            {
                m_calendarData[start]--;
                m_calendarData[end]++;

                return false;
                
            }
        }
        
        return true;
    }
    
private:
    
    map<int,int> m_calendarData;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */