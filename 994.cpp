/*
 * 994. Rotting Oranges
 */
 
class Solution {
public:
    
    class P{
    public:
        int x;
        int y;
        //int d;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS + dummy node
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        int M = grid.size(), N = grid[0].size();
        queue<P> q, qq;
        vector<vector<bool>> v(M, vector<bool>(N, false));
        for(int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); 
                    v[i][j] = true;
                }
            }
        }
        
        int res = 0;
        while(!q.empty()) {
            P t = q.front();
            q.pop();
            
            for(int i=0; i<4; ++i) {
                int xx = t.x + dx[i];
                int yy = t.y + dy[i];
                if (xx<0 || yy<0 || xx>=M || yy >=N || grid[xx][yy]!=1 || v[xx][yy]) {
                    continue;
                } else {
                    qq.push({xx, yy});  
                    v[xx][yy] = true;
                    grid[xx][yy] = 2;
                }
            }
            if (q.empty() && ! qq.empty()) {
                q = qq;
                qq = queue<P>();
                res++;
            }
        }
        
        // check if there are fresh orange
        for(int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return res;
        
    }
};
