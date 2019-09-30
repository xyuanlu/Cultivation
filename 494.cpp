/*
 *494. Target Sum
 *  You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
 *  Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 */
 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int K) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum;
        if (sum < K) return 0;
        // m[i][k] means number of ways ends at i addes to k
        vector<vector<int>> m(nums.size(), vector(2*sum+1, 0));
        m[0][offset+nums[0]] ++;
        m[0][offset-nums[0]] ++;
        
        
        for(int i=1; i<nums.size(); ++i) {
            for(int k=0; k < 2*sum+1; ++k) {
                if (k-nums[i]>=0 && k-nums[i]<2*sum+1 && m[i-1][k-nums[i]]) {
                    m[i][k] +=  m[i-1][k-nums[i]];
                    //cout<<i<<" "<<k<<" "<<m[i][k]<<endl;
                }
                if (k+nums[i]>=0 && k+nums[i]<2*sum+1 && m[i-1][k+nums[i]]) {
                    m[i][k] +=  m[i-1][k+nums[i]];
                    //cout<<i<<" "<<k<<" "<<m[i][k]<<endl;
                }
            }
            
        }
        
        
        return m[nums.size()-1][K+offset];
    }
};
