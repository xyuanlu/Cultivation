/*
 * 317. Shortest Distance from All Buildings
 *
 * You want to build a house on an empty land which reaches all buildings
 * in the shortest amount of distance. You can only move up, down, left and right.
 * You are given a 2D grid of values 0, 1 or 2, where:
 *
 * Each 0 marks an empty land which you can pass by freely.
 * Each 1 marks a building which you cannot pass through.
 * Each 2 marks an obstacle which you cannot pass through.
 * 
 * Example:
 *
 * Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
 * 
 *  1 - 0 - 2 - 0 - 1
 *  |   |   |   |   |
 *  0 - 0 - 0 - 0 - 0
 *  |   |   |   |   |
 *  0 - 0 - 1 - 0 - 0
 *
 */
 
class Solution {
public:
    /*
     * Staring from each building, do BFS to cound steps.
     *  1.Use vector<vector<bool>> visited to track if a node is visited in this session
     *  2. Update vector<vector<int>> reach, to indicate how many buildings can reach this point
     *  3. A candidate result point must be accessed by all buildings
     */
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    
    class point{
    public:
        int x;
        int y;
        
        point(int xx, int yy): x(xx), y(yy) {};
    };
    
    int shortestDistance(vector<vector<int>>& grid) {
        int M=grid.size(), N = grid[0].size();
        int res = 100000;
        int b=0;   // number of buildings met so far. 
        vector<vector<int>> distance(M, vector<int>(N, 0));
        vector<vector<int>> reach(M, vector<int>(N, 0));
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(grid[i][j] == 1) {
                    // BFS start with this point;
                    //cout<<i<<" "<<j<<endl;
                    b++;                            // << ------  count the number of buildings here.
                    queue<point> q, qq;
                    int step = 1;
                    q.push(point(i, j));
                    while(!q.empty()) {
                        point t = q.front();
                        int x = t.x, y = t.y;
                        q.pop();
                        for(int d=0; d<4; ++d) {
                            int xx = x+dx[d], yy = y+dy[d];
                            if(xx >=0 && yy >=0 && xx<M && yy <N &&
                               grid[xx][yy] == 0 && !visited[xx][yy]) {
                                visited[xx][yy] = true;
                                reach[xx][yy] ++;          // << --------- Update reach[][] here.
                                //cout<<xx<<" "<<yy<<endl;
                                distance[xx][yy] += step;
                                qq.push(point(xx, yy));
                            }
                        }
                        if(q.empty()) {
                            q = qq;
                            qq = queue<point>{};
                            step++;
                        }
                    } // while loop for bfs finishes here.
                    vector<vector<bool>> v(M, vector<bool>(N, false));
                    visited = v;
                } 
            }
        } // two for loops ends here.
        //cout<<"xx"<<endl;
        //bool reachble = false;
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(grid[i][j] == 0 && reach[i][j]==b) {      // << -----must be reachble by all buildings
                    res = min(res, distance[i][j]);
                }
            }
        }
        return res==100000? -1: res;
    }
};
