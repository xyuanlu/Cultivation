/*
 * 64. Minimum Path Sum
 * Given a m x n grid filled with non-negative numbers, find a path from top left to
 * bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */
 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M=grid.size(), N=grid[0].size();
        vector<vector<int>> m(M+1, vector<int>(N+1, INT_MAX));
        
        m[0][1] = m[1][0] = 0;
        
        for (int i=1; i<=M; ++i) {
            for(int j=1; j<=N; ++j) {
                m[i][j] = min(m[i-1][j], m[i][j-1]) + grid[i-1][j-1];
                //cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return m[M][N];
    }
    
};
