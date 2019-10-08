/*
 * 174. Dungeon Game
 */
 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // start from right bottom corner
        // if >0 then 0
        // else -x
        
        int M = dungeon.size(), N=dungeon[0].size();
        vector<vector<int>> m(M+1, vector<int>(N+1, -INT_MAX));
        m[M][N-1] = m[M-1][N] = 0;
        for(int i=M-1; i>=0; --i) {
            for(int j=N-1; j>=0; --j) {
                m[i][j] = min(0, dungeon[i][j]+max(m[i+1][j], m[i][j+1]));
            }
        }
        
        /*for(int i=0; i<=M; ++i) {
            for(int j=0; j<=N; ++j) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        return -m[0][0] +1 ;
    }
};
