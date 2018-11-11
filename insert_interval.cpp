/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end(), interval_compare);
        vector<Interval> result;

    
        for (int i = 0; i < intervals.size(); i++) {
            if (result.empty() || result.back().end < intervals[i].start) {
                result.push_back(intervals[i]);
            } else {
                result.back().end = max(result.back().end, intervals[i].end);
            }
        }
    
        return result;
    }
    
private:

    static bool interval_compare(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }
};