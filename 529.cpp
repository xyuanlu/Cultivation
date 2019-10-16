/*
 * 529. Minesweeper
 */
 
class Solution {
public:
    class P{
    public:
        int x;
        int y;
    };
    
    
    // Be careful with the visited matrix in BFS. the newly added node may be duplicat with
    // current level or previous level node but havent visited.
    // Update the visited matrix in the appending for loop. 
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //BFS
        int M=board.size(), N = board[0].size();
        
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        vector<vector<char>> res = board;
        
        if (board[click[0]][click[1]]=='M') {
            res[click[0]][click[1]] = 'X';
            return res;
        }
        
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        queue<P> q;
        q.push({click[0],click[1]});
        visited[click[0]][click[1]] = true;
        while(!q.empty()) {
            // If >0 of the blocks circles the nodes has mine, then update the node
            // else add all it's neighboors to the queue
            P t = q.front();
            q.pop();
            int x = t.x;
            int y = t.y;
            //visited[x][y] = true;
            int count = 0;
            for (int i=0; i<8; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx>=0 && yy>=0 && xx<M && yy<N) {
                    if (board[xx][yy] == 'M') {
                        count ++;
                    }
                }
            }
            if (count !=0) {
                res[x][y] = '0'+count;
            } else {
                res[x][y] = 'B';
                for (int i=0; i<8; ++i) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (xx>=0 && yy>=0 && xx<M && yy<N && !visited[xx][yy]) {
                        q.push({xx, yy});
                        visited[xx][yy] = true;      //<<------------ be careful here
                    }
                }
            }
        }
        return res;
    }
};
