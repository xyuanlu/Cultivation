/*
 * 4. Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 */
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m=nums1; vector<int> n=nums2;
        if (nums1.size()>nums2.size()) {
            m = nums2; n=nums1;
        }
        double res;
        int k = m.size() + n.size();
        if (k%2 ==0) {
            res = ( (double)helper(m, n, 0, 0, k/2) + 
                    (double)helper(m, n, 0, 0, k/2+1) )/2; 
        } else {
            res = helper(m, n, 0, 0, k/2+1);
        }
        return res;
    }
    
    /*
     * helper of finding kth element in m [i, end), n [j, end)
     * m.size() <= n.size
     * return n[k-1] when m searching range = 0
     * NOTE: We are finding the kth element. idx should be k-1.
     */
    
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) {
        vector<int> m=nums1;                //<------------ How can I avoid str copy...?
        vector<int> n=nums2;
        if (nums1.size()-i>nums2.size()-j) {
            m = nums2; n=nums1;
            int t=i;
            i=j; j=t;
        }
        
        //cout<<m.size()<<" "<<n.size()<<" "<<i<<" "<<j<<" "<<k<<endl;
        if (i==m.size()) {
            return n[k-1];
        }
        if (k==1) {
            return min(m[i], n[j]);
        }
        int idx1=0, idx2=0;
        idx1 = min((int)m.size()-1-i, k/2-1);
        idx2 = k-idx1-2;
        
        if (m[i+idx1]<= n[j+idx2]) {
            return helper(m, n, i+idx1+1, j, k-idx1-1);    // NOTE: k-(idx+1)th element.
        } else {
            return helper(m, n, i, j+idx2+1, k-idx2-1);
        }
        
    }
};
