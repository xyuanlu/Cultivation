/*
 * 16. 3Sum Closest
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */
 
 class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*
         * two pointer + BS
         */
        
        sort(nums.begin(), nums.end());
        
        int res, diff = INT_MAX;
        
        for(int i=0; i<nums.size()-2; ++i) {
            for(int j=i+1; j<nums.size()-1; ++j) {
                int t = nums[i] + nums[j];
                int m = helper(nums, j+1, target-t);
                //cout<<nums[i]<<" "<<nums[j]<<" "<<m<<endl;
                if (abs(target-(t+m))<diff) {
                    res = t+m;
                    diff = abs(target-(t+m));
                }
                if (abs(target-t-m) > diff) {
                    continue;
                }
            }
        }
        return res;
    }
    
    // find the cloest numster to tar
    int helper(vector<int>& nums, int l, int tar) {
        if (nums[l] > tar)
            return nums[l];
        int r = nums.size(), m;
        
        // find the last num <tar
        while(r-l>1) {
            m = l+(r-l)/2;
            if (nums[m] < tar) {
                l = m;
            } else {
                r = m;
            }
        }
        
        // compare nums[l] and nums[l+1];
        if (l == nums.size()-1 ||
            abs (tar-nums[l]) < abs(tar-nums[l+1])) {
            return nums[l];
        }
        return nums[l+1];
    }
};
