/*
 * 289. Game of Life
 */
 
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Since 0 and 1 only uses the least significant bit,
        // we can use the second bit for the new state
        
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                int c = helper(board, i, j);
                if ((board[i][j]==1 && (c==2 || c==3)) ||
                    (board[i][j]==0) && c==3){
                    board[i][j] += 2;
                }
                //cout<<c<<" ";
            }
            //cout<<endl;
        }
        
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                board[i][j] = board[i][j]/2;
            }
        }
    }
    
    int helper(vector<vector<int>>& board, int x, int y) {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int c = 0;
        
        for(int d=0; d<8; ++d) {
            int i = x+dx[d];
            int j = y+dy[d];
            if (i>=0 && j>=0 && i<board.size() && j<board[0].size() &&
                board[i][j]%2==1) {
                c++;
            }
        }
        
        return c;
        
    }
};
