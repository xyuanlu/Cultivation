/*
 * 1066. Campus Bikes II
 * 
 * On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M.
 * Each worker and bike is a 2D coordinate on this grid.
 *
 * We assign one unique bike to each worker so that the sum of the Manhattan distances
 * between each worker and their assigned bike is minimized.
 *
 * The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
 *
 * Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.
 */
 
class Solution {
public:
    // in these used condition, what's the min cost for the rest
    //map<pair<int, int>, int> m;
    
    unordered_map<int, int> m;   
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int res = 10*2*1000;
        
        int v=0, cur=0;
        
        // There is no such thing as BT + memo. No updating res and cur in dfs+memo.
        // BT is only for tree stucture subproblem 
        // memo if for problems with duplicats subproblems.
        helper(workers, bikes, 0, v); //, res, cur);
        // No need to use res and cur. 
        return m[0];
    }
    
    int com(int a, int b) {
        int res = a<<10 | b;
        return res;
    }
    
    int helper(const vector<vector<int>>& workers, const vector<vector<int>>& bikes,
                int widx, int v) { //, int& res, int cur) {
        
        if (widx == workers.size()) {
            //res = min(cur, res);
            return 0;
        }

        // This is wrong. This is WRONG, dont mixing subproblem with total.
        // We can not assume we will not need v' again. 
        //if (cur>res)     // <<<<<----- 
        //    return cur;
        
        if (m.find(com(widx, v))!=m.end()) {
            //cout<<"found "<< widx << " "<<v<<endl;
            //res = min(cur+m[com(widx, v)], res);   // <<-- If need to update res, dont forget to update res here
            return m[com(widx, v)];
        }
        
        int t = 10*2*1000;
        for (int j=0; j<bikes.size(); ++j) {
            if (v & 1<<j) {
                // jth bike is used
                continue;
            }
            int nv = v | 1<<j;
            int d = abs(workers[widx][0]-bikes[j][0]) + abs(workers[widx][1]-bikes[j][1]);
            //cout<<widx<<" "<<j<<" "<<d<<endl;
            int tt = d + helper(workers, bikes, widx+1, nv); //, res, cur+d);
            t = min(t, tt);
        }

        m[com(widx, v)] = t;
        return t;
    }
};
