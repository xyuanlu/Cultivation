/*
 * 1155. Number of Dice Rolls With Target Sum
 * You have d dice, and each die has f faces numbered 1, 2, ..., f.
 * Return the number of possible ways (out of fd total ways) modulo 10^9 + 7
 * to roll the dice so the sum of the face up numbers equals target.
 */
 
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        //m[i][k] number of ways to  using previous i items 
        // to reach sum k
        long long MOD = 1000000007;
        vector<vector<int>> m(d+1, vector<int>(target+1, 0));
        m[0][0] = 1;
        for(int i=1; i<=d; ++i) {
            for(int k=1; k<=target; ++k) {
                for(int j=1; j<=f; ++j) {
                    if (k-j<0)
                        continue;
                    m[i][k] = (m[i][k] + m[i-1][k-j]) % MOD ;
                }
            }
        }
        
        return m[d][target];
    }
};
