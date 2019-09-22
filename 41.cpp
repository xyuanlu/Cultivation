/*
 * 41. First Missing Positive
 * Given an unsorted integer array, find the smallest missing positive integer.
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // number '1' should be at the first position in the array
        for(int i=0; i<nums.size(); ++i) {
            while (nums[i] != i+1) {
                int t = nums[i];
                 // If we have duplicate, avoide infinity loop by 'nums[t-1] == t'
                if (t<=0 || t>nums.size() || nums[t-1] == t) {   
                    break;
                }
                //cout<<i<<" "<<t-1<<endl;
                swap(nums[i], nums[t-1]);
            }
        }
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]!= i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};
