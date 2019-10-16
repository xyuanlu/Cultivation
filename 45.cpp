/*
 * 45. Jump Game II
 * 
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
 */
 
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> m(nums.size(), nums.size());
//        vector<bool> n(nums.size(), false);
        
        if(nums.size()>1 && nums[0]==0) {
            return false;
        }
        
        m[0] = 0;
        //n[0] = true;
        
        for (int i=0; i<nums.size(); ++i) {
            int c = nums[i];
            int idx = i;
            int next = i;
            for(int j=i; j<nums.size(); ++j) {
                if (j>i+c) {
                    break;
                }
               // n[j] = true;
                m[j] = min(m[j], m[i]+1);
                if (j+nums[j] > idx) {
                    next = j;
                    idx = j+nums[j];
                }
            }
            if (next>i) {
                i=next-1;
            }
        }
        
       /* for (auto i:m) {
            cout<<i<<" ";
        }*/
        
        return m[nums.size()-1];
    }
};
