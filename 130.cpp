/*
 * 130. Surrounded Regions
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 */
 
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void solve(vector<vector<char>>& board) {
        if (board.size()==0)
            return;
        
        int M = board.size(), N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        // left and right
        for(int i=0; i<M; ++i) {
            // j=0
            helper(board, i, 0, visited, false);
            
            //j=board[0].size()
            helper(board, i, N-1, visited, false);
        }
        // top and bottom
        for(int j=0; j<N; ++j) {
            // top
            helper(board, 0, j, visited, false);
            // i=M-1
            helper(board, M-1, j, visited,false);
        }
        
        for(int i=1; i<M-1; ++i) {
            for(int j=1; j<N-1; ++j) {
                helper(board, i, j, visited, true);
            }
        }
    }
    
    // all 'O' can connect to boards are marked visited
    void helper(vector<vector<char>>& board, int i, int j,
                vector<vector<bool>>& visited, bool p) {
        
        int M = board.size(), N = board[0].size();
        if (i<0 || j<0 || i>=M || j>=N || board[i][j] == 'X' ||
            visited[i][j]) {
            return ;
        }
        
        if (p) {
            board[i][j] = 'X';
        }
        
        visited[i][j] = true;
        for(int d=0; d<4; ++d) {
            int xx = i+dx[d];
            int yy = j+dy[d];
            helper(board, xx, yy, visited, p);
        }
        
    }
};
