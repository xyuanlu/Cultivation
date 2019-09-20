/*
 * 674. Longest Continuous Increasing Subsequence
 *
 * Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> m(nums.size(), 1);
        int res = 1;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i]>nums[i-1])
                m[i] = m[i-1]+1;
            res = max(m[i], res);
        }
        return res;
    }
};
