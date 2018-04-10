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
    vector<Interval> merge(vector<Interval>& intervals) {

        std::sort(intervals.begin(), intervals.end(), customCompare);
        vector<Interval> result;

        int i = 0;
        int len = intervals.size();
        
        if (len >= 1) {
            Interval val(intervals[i].start, intervals[i].end);
            result.push_back(val);
            i++;
        }

        while (i < len) {
            if (intervals[i].start <= result.back().end) {
                result[result.size()-1]. end = max(intervals[i].end, result.back().end);
            } else {
                Interval val(intervals[i].start, intervals[i].end);
                result.push_back(val);
            }
            i++;
        }

        return result;
    }
    
private:
    
    static bool customCompare(Interval i1, Interval i2) {
        if (i1.start < i2.start) {
            return true;
        } else if (i1.start > i2.start) {
            return false;
        } else {
            return i1.end < i2.end;
        }
    }
};
