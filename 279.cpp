/*
 * 279. Perfect Squares
 *  Given a positive integer n, find the least number of perfect square
 *  numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 */
 
class Solution {
public:
    int numSquares(int n) {
        vector<int> m(n+1, n);
        m[0] = 0;
        m[1] = 1;
        
        for (int i=1; i<=n; ++i) {
            // for all squares before number i. 
            for (int s=1; s*s <= i; ++s) {
                m[i] = min(m[i], 1+m[i-s*s]);
            }
        }
        
        return m[n];
    }
};
