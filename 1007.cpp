/*
 * 1007. Minimum Domino Rotations For Equal Row
 */
 
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = helper(A, B);
        int b = helper(B, A);
        if (a!=-1 && b!=-1) {
            return min(a, b);
        } else {
            return max(a, b);
        }
        
    }
    
    int helper(vector<int>& A,vector<int>& B){
        vector<vector<int>> m(A.size(), vector<int>(2, A.size()+1));
        m[0][0] = 0; // no rotate
        m[0][1] = 1; // rotate
        
        for (int i=1; i<A.size(); ++i) {
            if (A[i] == A[i-1]) {
                m[i][0] = min(m[i][0], m[i-1][0]);
            }
            
            if (A[i] == B[i-1]) {
                m[i][0] = min(m[i][0], m[i-1][1]);
            }
            if (B[i] == B[i-1]) {
                m[i][1] = min(m[i][1], m[i-1][1])+1;
            }
            if (B[i] == A[i-1]) {
                m[i][1] = min(m[i][1], m[i-1][0])+1;
            }
            //cout<<m[i][0]<<" "<<m[i][1]<<endl;
        }
        
        int res = min(m[A.size()-1][0], m[A.size()-1][1]);
        if (res > A.size()) {
            return -1;
        }
       // cout<<res<<endl;
        return res;
    }
};
