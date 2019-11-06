/*
 * 718. Maximum Length of Repeated Subarray
 * Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
 */
 
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // m[i][j] : longest match substring contains A[i] and B[j]
        vector<vector<int>> m(A.size(), vector<int>(B.size(), 0));
        
        int res = 0;
        for(int i=0; i<A.size(); ++i) {
            for (int j=0; j<B.size(); ++j) {
                if (A[i] == B[j]) {
                    if (i==0 || j==0) m[i][j] = 1;
                    else m[i][j] = 1+m[i-1][j-1];
                }
                res = max(res, m[i][j]);
            }
        }
        return res;
    }
};
