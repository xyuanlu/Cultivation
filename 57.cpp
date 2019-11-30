/*
 * 57. Insert Interval
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 */
 
 class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
            
        int start = newInterval[0];
        int end = newInterval[1];
        int i=0;
        
        // all intervals before th new one
        while(i<intervals.size() && intervals[i][1] < start) {
            res.push_back(intervals[i]);
            ++i;
        }
        
        // merge
        while (i<intervals.size() && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            ++i;
        }
        res.push_back({start, end});
        
        // all intervals after the new 
        while (i<intervals.size())  {
            res.push_back(intervals[i]);
            ++i;
        } 
        
        if (res.size()==0 || res.back()[1]<start) {
            res.push_back(newInterval);
        }
        
        return res;
    }
};
