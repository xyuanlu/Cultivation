/*
 * 935. Knight Dialer
 * 
 * This time, we place our chess knight on any numbered key of a phone pad
 * (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.
 * Each time it lands on a key (including the initial placement of the knight), it
 * presses the number of that key, pressing N digits total.
 *
 * How many distinct numbers can you dial in this manner?
 *
 * Since the answer may be large, output the answer modulo 10^9 + 7.
 */
 
class Solution {
public:
    int MOD = 10e8+7;
    int knightDialer(int N) {
        if (N==0)
            return 0;
        // DFS + memorization
        vector<vector<vector<int>>> m(4, vector<vector<int>>(3, vector<int>(N+1, -1)));
        for (int i=0; i<4; ++i) {
            for (int j=0; j<3; ++j) {
                if (i!=4 && (j!=0 || j!=2)) {
                    m[i][j][0] = 0;
                    m[i][j][1] = 1;
                }
            }
        }
        int res = 0;
        for (int i=0; i<4; ++i) {
            for (int j=0; j<3; ++j) {
                if (i!=4 && (j!=0 || j!=2)) {
                    res += helper(i, j, m, N, 0) % MOD;
                    res = res % MOD;
                    //res += m[i][j][N];
                }
            }
        }
        return res;
    }
    
    
    int helper(int i, int j, vector<vector<vector<int>>>& m, int n, int cur) {
        if (i<0 || j<0 || i>3 || j>2 || (i==3 && (j==0 || j==2))) {
            return 0;
        }
        //cout<<i<<" "<<j<<endl;
        if (m[i][j][n] !=-1) {
            return m[i][j][n];
        }
        
        int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int res = cur;
        for (int d=0; d<8; ++d) {
            int xx = i+dx[d];
            int yy = j+dy[d];
            res += helper(xx, yy, m, n-1, cur) % MOD;
            res = res % MOD;
        }
        m[i][j][n] = res % MOD;
        return res;
    }
};
