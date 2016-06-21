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
        vector<Interval> res;
        int n=intervals.size();
        if(n<1) return res;
        sort(intervals.begin(),intervals.end(),
            [](Interval i1,Interval i2){return i1.start<i2.start;});
        res.push_back(intervals[0]);
        for(int i=0;i<n;i++)
        {
            if(res.back().end<intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end=max(res.back().end,intervals[i].end);
        }
        return res;
    }
};