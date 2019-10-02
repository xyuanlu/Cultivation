/*
 * 198. House Robber
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> m(nums.size()+1, 0);
        m[0] = 0;
        m[1] = nums[0];
        for(int i=2; i<=nums.size(); ++i) {
            m[i] = max(m[i-1], m[i-2]+nums[i-1]);
        }
        return m[nums.size()];
    }
};
