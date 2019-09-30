/*
 * 801. Minimum Swaps To Make Sequences Increasing
 * 
 * We have two integer sequences A and B of the same non-zero length.
 * We are allowed to swap elements A[i] and B[i].  Note that both elements
 * are in the same index position in their respective sequences.
 *
 * At the end of some number of swaps, A and B are both strictly increasing.  
 * (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)
 * 
 * Given A and B, return the minimum number of swaps to make both sequences strictly increasing. 
 * It is guaranteed that the given input always makes it possible.
 */
 
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<vector<int>> m(A.size(), vector<int>(2, A.size()+1));
        m[0][1] = 1;
        m[0][0] = 0;
        
        for(int i=1; i<A.size(); ++i) {
            //cout<<i<<endl;
            if(A[i]>A[i-1] && B[i]>B[i-1]) {
                m[i][0] = min(m[i][0], m[i-1][0]);   // No swap on both i and i-1
                m[i][1] = min(m[i][1], m[i-1][1]+1); // Swap on both i and i-1
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]) {
                m[i][0] = min(m[i][0], m[i-1][1]);  // Swap on i-1, no swap on i
                m[i][1] = min(m[i][1], m[i-1][0]+1); // Swap on i, no swap on i-1
                
            }
            //cout<<m[i][0]<<" "<<m[i][1]<<endl;
        }
        
        return min(m[A.size()-1][0], m[A.size()-1][1]);
    }
};
