/*
 * 560. Subarray Sum Equals K
 *
 * Given an array of integers and an integer k, you need to find the total number
 * of continuous subarrays whose sum equals to k.
 */
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum -> number of prefixes has this sum
        unordered_map<int, int> m;
        int sum = 0;
        int res = 0;
        m[0] = 1; 
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            int t = sum-k;
            if (m.find(t) != m.end()) {
                res += m[t];
            }
            m[sum]++;
        }
        return res;
    }
};
