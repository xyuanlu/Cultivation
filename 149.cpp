/*
 * 149. Max Points on a Line 
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */
 
 class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        // pair of slope and intersect -> count of point on this line
        
        int dup = 0;       // duplicate on each line
        int ver = 0;     // slope = 0
        int res = 0;
        
        for(int i=0; i<points.size(); ++i) {
            ver = 0; int same=0;
            int cur = 0;
            map<pair<int, int>, int> m;    //  <--------- map should start at each i
            for (int j=i+1; j<points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                // horizontal line
                if (x1==x2 && y1==y2) {
                    same++;
                    continue;
                }
                if (x1 == x2) {
                    ver++;
                    continue;
                }
                int dx = x1-x2;
                int dy = y1-y2;
                // std::gcd returns gcd of |a| and |b|
                // However, __gcd icludes sign
                int gcd = __gcd(dx, dy);   // greatest common divider
                //int slope = dx;
                //int intercept = dy;
                dx = dx/gcd;
                dy = dy/gcd;
               // cout<<i<<" "<<j<<" "<<dx<<" "<< dy<<endl;
                m[make_pair(dx, dy)] ++;
                cur = max(cur, m[make_pair(dx, dy)]);
            }
            res = max(res, max(ver, cur)+same+1);
        }
        return res;
    }
};
