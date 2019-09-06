/*
 * 1027. Longest Arithmetic Sequence
 *
 * Given an array A of integers, return the length of the longest arithmetic subsequence in A.
 */
 
 class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        /*
         * Trivial way is to use the same equation as Logest Feb sequence.
         *  -6136 ms, faster than 5.07% of C++ online submissions 
         */
        /*vector<vector<int>> m(A.size(), vector<int>(A.size(), 2));
        int res = 2;
        for(int i=0; i<A.size(); ++i)  {
            for(int j=0; j<i; ++j) {
                for(int k=0; k<j; ++k) {
                    if(A[j]-A[k] == A[i]-A[j]) {
                        m[i][j] = max(m[i][j], m[j][k] +1);
                        res = max(res, m[i][j]);
                    }
                }
            }
        }
        return res;*/
        
        /*
         * For each A[i]-A[j] pair, where j>i, we only care the last k where
         * A[j]-A[i] == A[i]-A[k].
         * So, we could have a cache for every value -> idx before i.
         * If there are suplicates, we only care the nearrest one.
         */
        int res = 2;
        vector<vector<int>> m(A.size(), vector<int>(A.size(), 2));
        unordered_map<int, int> prev;
        for(int i=0; i<A.size(); ++i) {
            for(int j=i+1; j<A.size(); ++j) {
                int t = A[j]-A[i];
                if(prev.find(A[i]-t) == prev.end())
                    continue;
                m[i][j] = m[prev[A[i]-t]][i] +1;
                res = max(res, m[i][j]);
            }
            prev[A[i]] = i;
        }
        return res;
    }
};
