/*
 * 1031. Maximum Sum of Two Non-Overlapping Subarrays
 * Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping
 * (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could
 * occur before or after the M-length subarray.)
 *
 * Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
 *
 * 0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
 * 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 */
 
 class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // prefix sum for vector l and vector m
        vector<int> a;
        int sum = 0;
        for(int i=0; i<A.size(); ++i) {
            sum += A[i];
            a.push_back(sum);
        }
        
        int res = INT_MIN;
        priority_queue<int> pqL, pqM;
        pqM.push(a[M-1]);
        pqL.push(a[L-1]);
        
        // the res starts from L+M-1,
        for(int i=L+M-1; i<A.size(); ++i) {
            //cout<<a[i] - a[i-M]<<" "<<a[i] - a[i-L]<<" "<<pqL.top()<<" "<<pqM.top()<<endl;
            // M size end with i,
            res = max(res, (a[i] - a[i-M] + pqL.top()));
            // L size wnd with i
            res = max(res, (a[i] - a[i-L] + pqM.top()));
            pqL.push(a[i-M+1] - a[i-M+1-L]);
            pqM.push(a[i-L+1] - a[i-M+1-L]);
        }
        return res;
    }
};
