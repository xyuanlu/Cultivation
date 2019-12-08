/*
 * 593. Valid Square
 * Given the coordinates of four points in 2D space, return whether the four points could construct a square.
 *
 * The coordinate (x,y) of a point is represented by an integer array with two integers.
 */
 
 class Solution {
public:
    class P{
    public:
        int x; 
        int y;
        
        P(vector<int> v) {
            x = v[0];
            y = v[1];
        }
        bool operator<(P& p1) const {
            if (x == p1.x) {
                return y<p1.y;
            }
            return x<p1.x;
        }
    };
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<P> points;
        points = {P(p1), P(p2), P(p3), P(p4)};
        sort(points.begin(), points.end());
        
        int dia1 = dis(points[0], points[3]);
        int dia2 = dis(points[1], points[2]);
        //cout<<dia1<<" "<<dia2<<endl;
        if (dia1 != dia2) return false;
        
        int l = dis(points[0], points[1]);
        if (l==0)
            return false;
        if (dis(points[3], points[1]) != l ||
            dis(points[3], points[2]) != l  ||
            dis(points[0], points[2]) != l )
            return false;
        
        return true;    
    }
    
    int dis(P& p1, P& p2) {
        return pow(abs(p1.x-p2.x),2) + pow(abs(p1.y-p2.y),2);
    }
};
