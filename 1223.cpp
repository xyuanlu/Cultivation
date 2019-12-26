/*
 * 1223. Dice Roll Simulation
 * A die simulator generates a random number from 1 to 6 for each roll. You introduced
 * a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 
 * 
 * Given an array of integers rollMax and an integer n, return the number of distinct sequences
 * that can be obtained with exact n rolls.
 *
 * Two sequences are considered different if at least one element differs from each other.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 */
 
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // m[i][k] is number of ways when we roll the ith
        // dice anends up with number k+1 [0~5] -> [1~6]
        
        // m[i][k] = sum(m[i-1][0~5]) - invalid
        // invalid = sum(m[i-h-1]) - m[i-h-1][k] 
        // if rollMax[5] = 4, invalid
        // ****666 = sum(***x) where x!=6
        
        long long MOD = 1000000007;
        vector<vector<int>> m(n, vector<int>(6, 0));
        vector<int> sums(n, 0);
        long long sum = 6, newSum = 0;
        for(int k=0; k<6; ++k) {
            m[0][k] = 1;
        } 
        
        for(int i=1; i<n; ++i) {
            sums[i-1] = sum %MOD;
            newSum = 0;
            for (int k=0; k<6; ++k) {
                int h = rollMax[k];
                m[i][k] = sum % MOD;
                if(h<=i) {
                    if (h==i) {
                        m[i][k] --;
                    } else {
                        // m[i][k] -= (sums[i-h-1] - m[i-h-1][k]);
                        m[i][k] = ((m[i][k] - sums[i-h-1] + m[i-h-1][k])%MOD +MOD)%MOD ;
                        
                    }
                }
                //newSum += m[i][k];
                newSum = (newSum % MOD + m[i][k]) % MOD; 
            }
            sum = newSum;
        }
        
        return (int)sum;
    }
};
