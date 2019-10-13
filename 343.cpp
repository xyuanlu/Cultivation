/*
 * 343. Integer Break
 *  Given a positive integer n, break it into the sum of at least two positive
 *  integers and maximize the product of those integers. Return the maximum product you can get.
 */

class Solution {
public:
    unordered_map<int, int> m;
    int integerBreak(int n) {
        // DFS + memorization
        return helper(n);
    }
    
    int helper(int n) {
        if (n==0) {
            return 0;
        }
        if (m.find(n) != m.end()) {
            return m[n];
        }
        int res = 1;
        for (int i=1; i<n; ++i) {
            res = max(res, max(n-i, helper(n-i)) * i);
        }
        m[n] = res;
        //cout<<n<<" "<<res<<endl;
        return res;
    }
};
