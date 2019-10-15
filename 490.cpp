/*
 * 490. The Maze
 */
 
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int M = maze.size(), N = maze[0].size();
        
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        return helper(maze, visited, destination, start[0], start[1]);
        
    }
    
    bool helper(vector<vector<int>>& maze, vector<vector<bool>>&  visited,
                vector<int>& destination, int x, int y) {
        int M = maze.size(), N = maze[0].size();
        
        if (x==destination[0] && y==destination[1]) {
            return true;
        }
        //cout<<x<<" "<<y<<endl;
        
        visited[x][y] = true;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        for(int i=0; i<4; ++i) {
            int xx=x, yy=y;
            while (xx>=0 && yy>=0 && xx<M && yy<N && maze[xx][yy]!=1) {
                xx = xx+dx[i];
                yy = yy+dy[i];
            }
            xx = xx-dx[i];
            yy = yy-dy[i];
            if (!visited[xx][yy]) {
                if (helper(maze, visited, destination, xx, yy))
                    return true;
            }
            
        }
        return false;
    }
};
 
