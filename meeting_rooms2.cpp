#include <queue>

class mycomparison
{
public:
  bool operator() (const Interval& lhs, const Interval &rhs) const
  {
    return lhs.end > rhs.end;
  }
};

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
        
        int result = 0;
        
        std::sort(intervals.begin(), intervals.end(), compare);
        
        priority_queue<Interval, std::vector<Interval>, mycomparison> pq;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            if (pq.empty() || intervals[i].start < pq.top().end)
            {
                pq.push(intervals[i]);
            }
            else
            {
                if (!pq.empty() && intervals[i].start >= pq.top().end)
                {
                    pq.pop();
                }
                pq.push(intervals[i]);
            }
        }
        
        return (int) pq.size();
    }
    
    static bool compare(const Interval &lhs, const Interval &rhs)
    {
        return lhs.start < rhs.start;
    }
};