/*
 * 1301. Number of Paths with Max Score
 */
 
 
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        long long MOD = 1e9+7;
        
        // max score we can reach at m[i][j]
        int M = board.size(), N = board[0].size();
        vector<vector<int>> m(M+1, vector<int>(N+1, 0));
        // number of path we can reach i j with max score
        vector<vector<int>> m2(M+1, vector<int>(N+1, 0));
        m2[M][N] = 1;
        
        for(int i=M-1; i>=0; --i) {
            for(int j=N-1; j>=0; --j) {
                if (board[i][j] == 'X')
                    continue;
                //cout<<m[i+1][j]<<" "<< m[i+1][j+1]<<" "<<m[i][j+1]<<endl;
                int temp = max({m[i+1][j], m[i+1][j+1], m[i][j+1]});
                //int res = 0;
                if (temp == m[i+1][j]) {
                    m2[i][j] = (m2[i][j] + m2[i+1][j]) % MOD;
                }
                if (temp == m[i+1][j+1]) {
                    m2[i][j] = (m2[i][j] + m2[i+1][j+1]) % MOD;
                }
                if (temp == m[i][j+1]) {
                    m2[i][j] = (m2[i][j] + m2[i][j+1]) % MOD;
                }
                //m2[i][j] = res;
                if (m2[i][j] !=0) {
                    if (board[i][j] == 'S' || board[i][j]=='E')
                        m[i][j] = temp;
                    else 
                        m[i][j] = (temp + (board[i][j] - '0')) % MOD;;
                } 
                
                //cout<<m[i][j]<<" ";
            }
        }
        
        return {m[0][0], m2[0][0]};
    }
};
