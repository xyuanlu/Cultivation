/*
 * 120. Triangle
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 */
 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> t(triangle.size(), INT_MAX);
        vector<int> tt = t;
        int prev = INT_MAX, res = INT_MAX;
        
        t[0] = triangle[0][0];
        
        for(int i=1; i<triangle.size(); ++i) {
            for (int j=0; j<triangle[i].size(); ++j) {
                if (j!=i)
                    tt[j] = min(prev, t[j]) + triangle[i][j];
                else
                    tt[j] = prev + triangle[i][j];
                prev = t[j];
            }
            t = tt;
            tt = vector<int>(triangle.size(), INT_MAX);
        }
        
        for(auto i:t) {
            res = min(res, i);
        }
        return res;
    }
};
