/*
 * 790. Domino and Tromino Tiling
 * We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.
 *
 * Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.
 * (In a tiling, every square must be covered by a tile. Two tilings are different if and only if there
 * are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)
 */

class Solution {
public:
    int numTilings(int N) {
        /*
         * if there is only Domino (XX)
         * then dp[i] = dp[i-1] + dp[i-2]
         */
        
        /*
         *                                   | 
         *                                   V
         * dp[i]][0] all rows non covered  XX
         *                                 XX
         * From XXC      XXCC        XXXC        XXCC
         *      XXC      XXAA        XXCC        XXXC   
         * dp[i-1][0]  dp[i-2][0]  dp[i-1][1] dp[i-1][2]
         *
         *                                   |
         *                                   V
         * dp[i][1] Upper rows covered     XXX
         *                                 XX
         *
         *                                   |
         *                                   V
         * dp[i][2] Lower rows covered     XX
         *                                 XXX
         */
        // if
        vector<vector<long long>> m(N+1, vector<long long>(3, 0));
        long long MOD = 1000000007;
        m[0][0] = 1;
        for(int i=1; i<=N; ++i) {
            long long temp = 0;
            if (i>1)
                temp = m[i-2][0];
            m[i][0] = ((((m[i-1][0]%MOD + temp)%MOD + m[i-1][1])%MOD + m[i-1][2])%MOD)%MOD;
            m[i][1] = (temp + m[i-1][2])%MOD;
            m[i][2] = (temp + m[i-1][1])%MOD;
        } 
        return m[N][0]%MOD;
        
    }
};
