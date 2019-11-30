/*
 * 1060. Missing Element in Sorted Array
 */
 
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int count = 0, res = 0;
        for(int i=1; i<nums.size(); ++i) {
            if (count + (nums[i] - nums[i-1]-1) <k) {
                count +=  nums[i] - nums[i-1]-1;
                //cout<<count<<endl;
                continue;
            }
            res = nums[i-1] + (k-count);
            count = k;
            break;
        }
        
        if (count < k) {
            res = nums.back() + k-count;
        }  
        return res;
    }
};
