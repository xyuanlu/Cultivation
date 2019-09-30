/*
 * 63. Unique Paths II
 * same as Unique Paths with obstacle
 */
 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) 
            return 0;
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<vector<long long>> m(M+1, vector<long long>(N+1, 0));
        m[0][1] = 1;
        for(int i=1; i<=M; ++i) {
            for(int j=1; j<=N; ++j) {
                if(obstacleGrid[i-1][j-1] != 1) {
                    //cout<<i<<" "<<j<<endl;
                    m[i][j] = m[i-1][j] + m[i][j-1];
                }
            }
        }
        return m[M][N];
    }
};
