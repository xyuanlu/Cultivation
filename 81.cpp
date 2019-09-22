/*
 * 81. Search in Rotated Sorted Array II
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
 * Would this affect the run-time complexity? How and why?  - worst case -O(n) 
 */
 
 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // if n[l] == n[m], then there must be anther number whos value ==n[l]
        // move left +1 until l==m or n[l]!= m[m]
        if(nums.size()==0)
            return false;
        int l=0, r=nums.size(), m;
        while (r-l>1) {
            m=l+(r-l)/2;
            if (l<m && nums[l]==nums[m]) {
                ++l;
                continue;
            }
            //cout<<l<<" "<<m<<" "<<r<<endl;
            if (nums[l] < nums[m]) {   // left part is sorted
                if(nums[l]<= target && nums[m]>target) {
                    r = m;
                } else {
                    l = m;
                }
            } else {                  // right part is sorted
                if(nums[m]<= target && nums[r-1]>=target){
                    l = m;
                } else {
                    r = m;
                }
            }
        }
        return nums[l] == target;
    }
};
