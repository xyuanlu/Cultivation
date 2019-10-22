/*
 * 1091. Shortest Path in Binary Matrix
 */
 
class Solution {
public:
    class P{
    public:
        int x;
        int y;
        int step;
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS 
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int N = grid.size();
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<P> q;
        q.push({0, 0, 1});
        visited[0][0] = true;
        
        if (N>0 && grid[0][0]==1)
            return -1;
        
        while(!q.empty()) {
            P t = q.front();
            if (t.x == grid.size()-1 && t.y == grid.size()-1) {
                return t.step;
            }
            q.pop();
            for (int i=0; i<8; ++i) {
                int xx = t.x+dx[i];
                int yy = t.y+dy[i];
                if (xx>=0 && yy>=0 && xx<N && yy<N && !visited[xx][yy] && grid[xx][yy]==0) {
                    q.push({xx, yy, t.step+1});
                    visited[xx][yy] = true;
                }
                
            }
        }
        
        return -1;
        
    }
};
