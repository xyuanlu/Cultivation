/*
 * 31. Next Permutation
 */
 
 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
         * From least significant bit (right) to left.
         * Find the first decreasing (num[i-1]<num[i])
         * swap nums[i-1] with the smmalest number num[j] larger
         * than nums[i-1] where j>i-1;
         *
         * Since the subarray after i is decreasing (i->end)
         * Reverse the subarray.
         */
        
        int i=nums.size()-1;
        for(; i>0; --i) {
            if (nums[i]>nums[i-1]) {
                int h=nums.size()-1;
                for(; h>i; --h) {
                    if(nums[h]>nums[i-1])
                        break;
                }
                //cout<<h<<endl;
                int k=0; k=nums[h];
                nums[h] = nums[i-1];
                nums[i-1] = k;
                break;
            }
        }
        //cout<<i<<endl;
        reverse(nums.begin()+i, nums.end());
    }
};
