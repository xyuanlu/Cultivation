/*
 * 939. Minimum Area Rectangle
 * Given a set of points in the xy-plane, determine the minimum area of a rectangle
 * formed from these points, with sides parallel to the x and y axes.
 *
 * If there isn't any rectangle, return 0.
 */
 
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // find diagnal 
        // for pair [1,4], [2,5], find if we have [2,4] and [1, 5]
        // save the diagnal.
        int res = 40000 * 40000+1;
        
        // We need to create own hasher
        unordered_set<int> m;
        
        // adding all pairs in the map
        for(int i=0; i<points.size(); ++i) {
            m.insert(hasher(points[i][0],points[i][1]));
        }
        
        for(int i=0; i<points.size()-1; ++i) {
            for(int j=i+1; j<points.size(); ++j) {
                int a = points[i][0];
                int b = points[i][1];
                int c = points[j][0];
                int d = points[j][1];
                if (a==c || b == d)
                    continue;
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                if (m.find(hasher(a,d)) == m.end() ||  m.find(hasher(c, b))== m.end())
                    continue;
                res = min(abs(a-c) * abs(b-d), res);
            }
        }
        return res>40000 * 40000? 0: res;
    }
    
    int hasher(int x, int y) {
        return x*4000 + y;
    }
};
