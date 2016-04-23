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
        int n=intervals.size();
        vector<Interval> res;
        int i=0;
        for(;i<n;i++)
        {
            if(newInterval.end<intervals[i].start)
                break;
            else if(newInterval.start>intervals[i].end)
                res.push_back(intervals[i]);
            else
            {
                newInterval.start=min(newInterval.start,intervals[i].start);
                newInterval.end=max(newInterval.end,intervals[i].end);
            }
        }
        res.push_back(newInterval);
        for(;i<n;i++)
            res.push_back(intervals[i]);
        return res;
    }
};