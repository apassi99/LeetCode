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
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {

        int len = (int) intervals.size();
        
        sort(intervals.begin(), intervals.end(), compareIntervals);
        
        priority_queue<int, std::vector<int>, std::greater<int> > endTimes;

        for (int i = 0; i < len; i++) {
            
            if (!endTimes.empty() && intervals[i].start >= endTimes.top()) {
                endTimes.pop();
            }
            endTimes.push(intervals[i].end);
        }
        
        return (int) endTimes.size();
    }
    
private:

    static bool compareIntervals(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }
};