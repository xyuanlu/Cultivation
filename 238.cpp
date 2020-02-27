/*
 * 238. Product of Array Except Self
 */
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        
        // res[i] is product of [0, i-1]
        int temp = 1;
        for(int i=0; i<nums.size(); ++i) {
            res[i] = temp;
            temp = temp*nums[i];
        }
        
        temp = nums.back();
        for(int i = nums.size()-2; i>=0; --i) {
            res[i] = res[i] * temp;
            temp = temp*nums[i];
        }
        return res;
    }
};
