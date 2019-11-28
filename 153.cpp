/*
 * 153. Find Minimum in Rotated Sorted Array
 * no duplicate
 */
 
class Solution {
public:
    int findMin(vector<int>& nums) {
        // ( ] , find the sorted and unsorted part
        // the min is always on the unsorted part, if ( ]
        
        int l=-1, r=nums.size()-1; 
        while(r>l+1) {
            int m = l+(r-l)/2;
            if (nums[l+1] <= nums[m] && nums[m]<nums[r]) {
                return nums[l+1];
            }
            if (nums[m]<nums[r]) {
                // right part is sorted
                r = m;
            } else {
                l=m;
            }
        }
        return nums[r];
    }
};
