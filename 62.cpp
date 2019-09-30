/*
 * 62. Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 */
 
class Solution {
public:
    int uniquePaths(int x, int y) {
        vector<vector<int>> m(x+1, vector<int>(y+1, 0));
        m[0][1]= 1;                        // <--------------
        for(int i=1; i<=x; ++i) {
            for(int j=1; j<=y; ++j) {
                m[i][j] = m[i-1][j] + m[i][j-1];
                //cout<<m[i][j]<<" ";
            }
            //cout<<endl;
        }
        return m[x][y];
    }
};
