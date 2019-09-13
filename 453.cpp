/*
 * 452. Minimum Number of Arrows to Burst Balloons
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 104 balloons.
 *
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart
 * ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow
 * once shot keeps travelling up infinitely. The problem is to find the minimum number
 * of arrows that must be shot to burst all balloons.
 * 
 * [[10,16], [2,8], [1,6], [7,12]] -> 2
 */
 
 class Solution {
public:
    static 
    bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
    // burst when overlap, curEnd = min(curEnd, points[i][1]);
    // only need to iterate through begin points
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
       /* for(auto i:points) {
            cout<<i[0]<<"-"<<i[1]<<" ";
        }*/
        cout<<endl;
        
        int res = 0, curEnd = points[0][1];
        bool overlap = false;
        for(int i=1; i<points.size(); ++i) {
            // no overlap, next.start >= cur.end
            //cout<<points[i][0] <<" "<< curEnd<<endl;
            if(points[i][0] > curEnd) {
                if(overlap == false)
                    res++;
                curEnd = points[i][1];
                overlap = false;
            } else {
                curEnd = min(curEnd, points[i][1]);
                if(overlap == false) {
                    res ++;
                    overlap = true;
                }
            }
        }
        if(overlap == false)
            res++;
        
        return res;
    }
};
 
