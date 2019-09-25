/*
 * 286. Walls and Gates
 * You are given a m x n 2D grid initialized with these three possible values.
 *
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as
 * you may assume that the distance to a gate is less than 2147483647.
 * Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
 */
 
 class Solution {
public:
    class P{
    public:
        int x;
        int y;
        P(int xx, int yy):x(xx), y(yy) {};
    };
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size()==0)
            return;
        for(int i=0; i<rooms.size(); ++i) {
            for(int j=0; j<rooms[0].size(); ++j) {
                if(rooms[i][j] == 0) {
                    // do BFS from this gate
                    helper(rooms, i, j);
                }
            }
        }
    }
    
    void helper(vector<vector<int>>& rooms, int i, int j) {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        int step = 0;
        int M=rooms.size(), N=rooms[0].size();
        //vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        queue<P> q, qq;
        q.push(P(i, j));
        while(!q.empty()) {
            P temp = q.front();
            q.pop();
            int x = temp.x;
            int y = temp.y;
            //visited[x][y] = true;
            if(rooms[x][y]>step) {
                rooms[x][y] = step;
            }
            for(int i=0; i<4; ++i) {
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx>=0 && yy >=0 && xx < M && yy < N &&
                   //visited[xx][yy] == false &&     // <------ Do not need visited here 
                   rooms[xx][yy]>0 && 
                   step < rooms[xx][yy]) {         // If we compare step and cur min val
                    qq.push(P(xx, yy));
                }
            }
            if(q.empty()) {
                step++;
                q = qq;
                qq = queue<P>();
            }
        }
    }
};
