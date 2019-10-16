/*
 * 55. Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 */
 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1;
        
        for(int i=nums.size()-2; i>=0; --i) {
            if(i+nums[i]>=target) {
                target = i;
            }
        }
        return target ==0;
        
    }
    
    
    
    bool canJump2(vector<int>& nums) {
        vector<bool> m(nums.size(), false);
        
        if(nums[0]==0 && nums.size()>1)
            return false;
        m[0] = true;
        
        for(int i=0; i<nums.size(); ++i) {
            int n = nums[i];
            int idx = i;
            int next = i;
            if (!m[i])
                continue;
            for (int j=i; j<nums.size(); ++j) {
                if (j==i+n+1)
                    break;
                m[j] = true;
                if (j+nums[j] > idx) {
                    idx = j+nums[i];
                    next = j;
                }
            }
            if (next>i)
                i = next-1;   
        }
        
        /*for(int i:m) {
            cout<<i<<" ";
        }*/
        
        return m[nums.size()-1];
    }
};
