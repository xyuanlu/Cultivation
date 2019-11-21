/*
 * 419. Battleships in a Board
 * 
 *  Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's,
 * empty slots are represented with '.'s. You may assume the following rules:
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words, they can only be made of
 * the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
 */
 
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res=0;
        
        for(int i=0; i<board.size(); ++i) {
            bool prev = false;  // if previous is 'X'
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    prev = false;
                    continue;
                }
                if (board[i][j] == 'X' && !prev && (i==0 || board[i-1][j]=='.')) {
                    res++;
                    prev = true;
                }
            }
        }
        
        return res;
    }
};
