/*
 * 1272. Remove Interval
 * Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents
 * the set of real numbers x such that a <= x < b.
 *
 * We remove the intersections between any interval in intervals and the interval toBeRemoved.
 *
 * Return a sorted list of intervals after all such removals.
 */
 
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        
        int i=0;
        for(; i<intervals.size(); ++i) {
            if (intervals[i][1] < toBeRemoved[0]) {
                res.push_back(intervals[i]);
            } else {
                break;
            }
        }
        if (i == intervals.size())
            return res;
        
        if (intervals[i][1]>toBeRemoved[0] && intervals[i][0]< toBeRemoved[0])
            res.push_back({intervals[i][0], toBeRemoved[0]});
        
        // find the first interval whos's begin >= toBeRemoved.end
        // F F T T
        int l = i-1, r = intervals.size(), m;
        if (intervals[intervals.size()-1][0] > toBeRemoved[1]) {
            r = r-1;
            while(r>l+1) {
                m = l + (r-l)/2;
                if (intervals[m][0] >= toBeRemoved[1]) {
                    r = m;
                } else {
                    l = m;
                }
            }
        }
        cout<<r<<endl;
        if (r!=0 && intervals[r-1][1]>toBeRemoved[1])
            res.push_back({toBeRemoved[1], intervals[r-1][1]});
        
        while(r<intervals.size()) {
            res.push_back(intervals[r]);
            ++r;
        }
        return res;
    }
};
