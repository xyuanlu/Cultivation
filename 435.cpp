/*
 * 435. Non-overlapping Intervals
 *
 * Given a collection of intervals, find the minimum number of intervals
 * you need to remove to make the rest of the intervals non-overlapping.
 */
 
 class Solution {
public:
    static 
        bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0])
            return a[1]<b[1];
        else
            return a[0]<b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() ==0)
            return 0;
        int res = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int curEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0]<curEnd) { // overlap
                res++;
                // remove the interval that has larger end point
                curEnd = min(curEnd, intervals[i][1]);
            } else 
            curEnd = intervals[i][1];
        }
        return res;
    }
};
