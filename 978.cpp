/*
 * 978. Longest Turbulent Subarray
 * 
 * A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
 * For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
 * OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
 * That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
 */
 
 class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        if(nums.size() ==0) 
            return 0;
        vector<int> m(nums.size(), 1);
        int res = 1;
        for (int i=1; i<nums.size(); ++i) {
            //cout<<i<<endl;
            if (nums[i] == nums[i-1])
                continue;
            if (i>1 && (nums[i]>nums[i-1] && nums[i-1]>nums[i-2]
                    ||  nums[i]<nums[i-1] && nums[i-1]<nums[i-2]))
                m[i] = 2;
            else
                m[i] = 1+m[i-1];
            res = max(res, m[i]);
        }
        return res;
    }
};
