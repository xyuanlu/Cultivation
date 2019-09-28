/*
 * 79. Word Search
 */
 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)
            return word.size()==0;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                if(board[i][j] == word[0]) {
                    if (helper(board, word, 0, i, j, visited))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool helper(const vector<vector<char>>& board, const string& word,
               int idx, int x, int y, vector<vector<bool>>& visited) {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        
        if(idx == word.size())
            return true;
        
        if (x<0 || y<0 || x>=board.size() || y>=board[0].size() 
           || visited[x][y]== true || board[x][y]!=word[idx]) {
            return false;
        }
        visited[x][y] = true; 
        bool found = false;
        
        for(int i=0; i<4; ++i) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            found = helper(board, word, idx+1, xx, yy, visited);
            if(found)
                break;
        }
        visited[x][y] = false;
        return found;
    }
};
