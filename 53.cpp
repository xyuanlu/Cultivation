/*
 * 53. Maximum Subarray
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest
 * sum and return its sum.
 */
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        }
        // m[i] is the largest subarray ends at i
        vector<int> m(nums.size(), nums[0]);
        int res = nums[0];
        
        for(int i=1; i<nums.size(); ++i) {
            m[i] = max(nums[i], nums[i]+m[i-1]);
            res = max(res, m[i]);
        }
        return res;
    }
};
