/*
 * 325. Maximum Size Subarray Sum Equals k
 * Given an array nums and a target value k, find the maximum length of a
 * subarray that sums to k. If there isn't one, return 0 instead.
 */
 
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        
        // Ref map. pre fix sum value -> idx
        // Since we compute the prefix sum from begin to end,
        // idx vectoer is in a increasing order.
        // we only need to fetch the first.
        unordered_map<int, vector<int>> m;
        
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) {
                res = max(res, i+1);
                //cout<<i<<endl;
            }
            
            if (m.find(sum-k) != m.end()) {
                int idx = m[sum-k][0]; 
                res = max(res, i-idx);
                //cout<<idx<<" "<<i<<endl;
            }
            m[sum].push_back(i);
        }
        
        return res;
        
    }
};
