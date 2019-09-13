/*
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order, find the starting and ending position
 * of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */
 
 class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0 || nums[0]>target || nums[nums.size()-1] <target)
            return {-1,-1};
        vector<int> res;
        int l=0, r=nums.size(), m;
        if(nums[0] == target) {
            res.push_back(0);
        } else {
            while(r-l>1) {
                m = l+(r-l)/2;
                if(nums[m]<target) {
                    l=m;
                } else {
                    r=m;
                }
            }
            if (l == nums.size()-1 || nums[l+1]!=target) {
                cout<<l<<endl;
                return {-1,-1};
            } else {
                res.push_back (l+1);
            }
        }
        
        l=0; r=nums.size();
        while(r-l>1) {
            m = l+(r-l)/2;
            if (nums[m] <= target) {
                l=m;
            } else {
                r=m;
            }
        }
        res.push_back(l);
        return res;
    }
};
