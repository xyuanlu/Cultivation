/*
 * 1057. Campus Bikes
 * On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M.
 * Each worker and bike is a 2D coordinate on this grid.
 *
 * Our goal is to assign a bike to each worker. Among the available bikes and workers,
 * we choose the (worker, bike) pair with the shortest Manhattan distance between each
 * other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs
 * with the same shortest Manhattan distance, we choose the pair with the smallest worker
 * index; if there are multiple ways to do that, we choose the pair with the smallest bike index).
 * We repeat this process until there are no available workers.
 *
 * The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
 * 
 * Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.
 */
 
class Solution {
public:
    class P{
    public:
        int w;
        int b;
        int d;
        
        P(int ww, int bb, int dd): w(ww), b(bb), d(dd) {};
        
        
        // 
        bool operator<(const P& pp) const {
            if (d == pp.d) {
                if (w != pp.w)
                    return w>pp.w;
                else
                    return b > pp.b;
            }
            else
                return d>pp.d;
        }
    };
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> res(workers.size(), -1);
        
        int v = 0;
        vector<bool> vb(bikes.size(), false);
        vector<bool> vw(workers.size(), false);
        
        priority_queue<P> pq;
        
        for(int i=0; i<workers.size(); ++i) {
            for(int j=0; j<bikes.size(); ++j) {
                int d = abs(workers[i][0]-bikes[j][0]) +  abs(workers[i][1]-bikes[j][1]);
                //if (i==8 && (j==64 || j==1))
                  //  cout<<i<<" "<<j<<" "<<d<<endl;
                pq.push(P(i, j, d));
            }
        }
        
        while (v<workers.size()) {
            P t = pq.top();
            if (!vw[t.w] && !vb[t.b]) {
                res[t.w] = t.b;
                v++;
                vb[t.b] = true;
                vw[t.w] = true;
            }
            pq.pop();
        }
        return res;
    }
};
