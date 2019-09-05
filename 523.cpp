/*
 * Given a list of non-negative numbers and a target integer k, write a function to check
 * if the array has a continuous subarray of size at least 2 that sums up to a multiple of
 * k, that is, sums up to n*k where n is also an integer.
 *
 * Example 1:
 *
 *  Input: [23, 2, 4, 6, 7],  k=6
 *  Output: True
 *  Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
 *
 * Example 2:
 *
 *  Input: [23, 2, 6, 4, 7],  k=6
 *  Output: True
 *  Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 *
 * Runtime: 28 ms, faster than 81.23% of C++ online submissions for Continuous Subarray Sum.
 * Memory Usage: 12.3 MB, less than 5.00% of C++ online submissions for Continuous Subarray Sum.
 */
 
 class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*
         * K can be 0  , n can be 0       
         */
        k = abs(k);
        unordered_map<int, vector<int>> m;    // a vector of idx in nums whos preFix_sum%k == i
        int sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == 0 && i+1<nums.size() && nums[i+1] == 0)
                return true;
        }
        if(k==0)
            return false;
        m[0] = {-1};
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            int remain = sum%k;
            if (m[remain].size() !=0) {
                for (auto idx:m[remain]) {
                    if ((i-idx)>1)
                        return true;
                }
            }
            m[sum%k].push_back(i);
        }
        return false;
    }
};
