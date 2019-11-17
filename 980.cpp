/*
* 980. Unique Paths III
* 
* On a 2-dimensional grid, there are 4 types of squares:
* from start '1' to dest '2', can walk over '0' and '-1'is obstacle
* Return the number of 4-directional walks from the starting square to the ending
* square, that walk over every non-obstacle square exactly once.
*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // count the number of 0's in the matrix
        // also find the starting and ending point
        int k=1, sx, sy;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++k;
                }
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        cout<<k<<endl;
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        return helper(grid, sx, sy, k, visited);
    }
    
    int helper(vector<vector<int>>& grid, int x, int y, int k,
               vector<vector<bool>>& visited) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        //cout<<x<<" "<<y<<" "<<k<<endl;
        if (x<0 || y<0 || x>=grid.size() || y>=grid[0].size() ||
            grid[x][y] ==-1 || visited[x][y]) 
            return 0;
        //cout<<x<<" "<<y<<" "<<k<<endl;
        if (grid[x][y]==2) {
            if (k==0)
                return 1;
            return 0;
        }
        int res = 0;
        visited[x][y] = true;
        // k must be 0 here (or start point 1)
        for (int d=0; d<4; ++d) {
            int xx = x+dx[d];
            int yy = y+dy[d];
            res += helper(grid, xx, yy, k-1, visited);
        }
        visited[x][y] = false;
        return res;
    }
};
