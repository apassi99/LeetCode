/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i-1].end > intervals[i].start)
            {
                return false;
            }
        }
        return true;
    }
    
    static bool compare(const Interval &i1, const Interval &i2)
    {
        return i1.start < i2.start;
    }
};