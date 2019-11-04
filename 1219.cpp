/*
 * 1219. Path with Maximum Gold
 */
 class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int M = grid.size(), N = grid[0].size();
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if (grid[i][j] !=0) {
                    vector<vector<bool>> visited(M, vector<bool>(N, false));
                    visited[i][j] = true;
                    res = max(res, helper(grid, i, j, grid[i][j], visited));
                }
            }
        }
        return res;
    }
    
    int helper(const vector<vector<int>>& grid, int i, int j,
               int cur, vector<vector<bool>>& v) {
        int M = grid.size(), N = grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int res = cur;
        for (int d=0; d<4; ++d) {
            int xx = i+dx[d];
            int yy = j+dy[d];
            if (xx<0 || yy<0 || xx>=M || yy>=N || v[xx][yy] || grid[xx][yy] == 0) {
                continue;
            }
            v[xx][yy] = true;
            res = max(res, helper(grid, xx, yy, cur+grid[xx][yy], v));
            v[xx][yy] = false;
        }
        return res;
        
    }
};
