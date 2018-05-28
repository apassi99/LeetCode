/**
 * Definition of Interval:
 * classs Interval {
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
        // Write your code here
        
        if (intervals.empty()) {
            return true;
        }

        std::sort(intervals.begin(), intervals.end(), Solution::compareIntervals);
        
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i+1].start < intervals[i].end) {
                return false;
            }
        }
        
        return true;
    }
    
private:

    static bool compareIntervals(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }
};