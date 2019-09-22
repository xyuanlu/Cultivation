/*
 * 1004. Max Consecutive Ones III
 * 
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 *
 * Return the length of the longest (contiguous) subarray that contains only 1s. 
 *
 */
 
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // two pointer + sliding window.
        int k=0, l=0, r=l;
        int res = 0;
        if(K==0) {
            int t=0;
            for(int i=0; i<A.size(); ++i) {
                if(A[i]==1) {
                    t++;
                    res = max(res, t);
                } else {
                    t=0;
                }
            }
            return res;
        }
        
        while (r<A.size()) {
            //cout<<l<<" "<<r<<" "<<k<<endl;
            if(A[r] == 0) {
                ++k;
            }
            if(k==K) {
                while(r<A.size()-1 && A[r+1]==1)
                    ++r;
                res = max(res, r-l+1);    
                    
                while(l<r && A[l]!=0) {    // stop when pass the first '0'
                    ++l;
                }
                if(A[l]==0) {
                    ++l;
                    --k;
                }
                //cout<<l<<" "<<k<<endl;
            }
            ++r;
        }
        return max(res, r-l);
    }
};
