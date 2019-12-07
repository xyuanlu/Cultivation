/*
 * 773. Sliding Puzzle
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
 * 
 * A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
 *
 * The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
 * 
 * Given a puzzle board, return the least number of moves required so that the state of the board is solved.
 * If it is impossible for the state of the board to be solved, return -1.
 *
 * Input: board = [[4,1,2],[5,0,3]]
 * Output: 5
 * Explanation: 5 is the smallest number of moves that solves the board.
 * An example path:
 * After move 0: [[4,1,2],[5,0,3]]
 * After move 1: [[4,1,2],[0,5,3]]
 * After move 2: [[0,1,2],[4,5,3]]
 * After move 3: [[1,0,2],[4,5,3]]
 * After move 4: [[1,2,0],[4,5,3]]
 * After move 5: [[1,2,3],[4,5,0]]
 */
 
 
class Solution {
public:
    class P{
    public:
        string s;   // current state
        int idx;      // where 0 is
        int step;
    };
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        unordered_set<string> v;
        queue<P> q;
        string s;
        int ii, jj;
        for(int i=0; i<2; ++i) {
            for (int j=0; j<3; ++j) {
                s += '0' + board[i][j];
                if (board[i][j] == 0) {
                   ii = i;
                    jj = j;
                }
            }
        }
        if (s == target)
            return 0;
        q.push({s, ii*3+jj, 0});
        v.insert(s);
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        
        while(!q.empty()) {
            P t = q.front();
            q.pop();
            //cout<<t.s<<" "<< t.idx<<endl;
            int x = t.idx/3;
            int y = t.idx%3;
            for(int i=0; i<4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                // if xx and yy is valid
                if (xx >=0 && yy >=0 && xx<2 && yy<3) {
                    int newIdx = xx*3 + yy;
                    char cc = t.s[newIdx];
                    string ss = t.s;
                    ss[t.idx] = cc;
                    ss[newIdx] = '0';
                    if (ss == target) {
                        return t.step+1;
                    }
                    //cout<<ss<<endl;
                    if (v.find(ss) != v.end()) {
                        continue;
                    }
                    else {
                        v.insert(ss);
                        q.push({ss, newIdx, t.step+1});
                    }
                }
            }
            
        }
        
        return -1;
    }
};
