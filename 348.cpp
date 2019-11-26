/*
 * 348. Design Tic-Tac-Toe
 */
 
class TicTacToe {
public:
    /*
     * Since all moves are valid, we can just track
     * the numebr of item on each players row and colume
     * and diagonal.
     */
    
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        roww = vector<vector<int>> (2, vector<int>(n, 0));
        coll = vector<vector<int>> (2, vector<int>(n, 0));
        dia = vector<int>(2, 0);
        rdia = vector<int>(2, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        roww[player-1][row] ++;
        //cout<<"r "<<roww[player-1][row]<<endl;
        if (roww[player-1][row] == N) {
            return player;
        }
        coll[player-1][col] ++;
        //cout<<"c "<<coll[player-1][col]<<endl;
        if (coll[player-1][col] == N) {
            return player;
        }
        
        if (row == col) {
            dia[player-1]++;
            if (dia[player-1]==N)
                return player;
        }
        if (row+col+1 == N) {
            rdia[player-1]++;
            if (rdia[player-1]==N)
                return player;
        }
        return 0;
    }
    
private:
    int N;
    vector<vector<int>> roww;
    vector<vector<int>> coll;
    vector<int> dia, rdia;  
    // dia -> diagnal from left top to right down
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
