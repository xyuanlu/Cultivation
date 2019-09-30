/*
 416. Partition Equal Subset Sum
 
  Given a non-empty array containing only positive integers,
  find if the array can be partitioned into two subsets such
  that the sum of elements in both subsets is equal.

  Note:

  Each of the array element will not exceed 100.
  The array size will not exceed 200.

*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // DP - targetsum
        int t = 0;
        for(int i:nums) {
            t += i;
        }
        if(t%2 !=0) return false;
        t = t/2;
        
        /*vector<vector<bool>> m(nums.size(), vector<bool>(max(nums[0], t)+1, false));
        m[0][0] = true;
        m[0][nums[0]] = true;
        for(int i=1; i<nums.size(); ++i) {
            m[i][0] = true;
            for(int j=0; j<=t; ++j) {
                m[i][j] = m[i-1][j];
                if(j-nums[i]>=0)
                    m[i][j] =  m[i][j]|| m[i-1][j-nums[i]];
            }
        }
        
        return m[nums.size()-1][t];*/
        vector<int> m(t+1, 0);
        m[0] = true;
        for(int i=0; i<nums.size(); ++i) {
            for(int j=t; j>=0; --j) {
                if(m[j] &&j+nums[i]>=0 && j+nums[i]<=t ) {
                    m[j+nums[i]] = true;
                }
            }
        }
        return m[t];
    }
};
