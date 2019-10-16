/*
 * 300. Longest Increasing Subsequence
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 */
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        // value -> idx
        map<int, int> n;
        vector<int> m(nums.size(), 1);
        int res=0;
        
        for(int i=0; i<nums.size(); ++i) {
            int t = 0;
            for (auto& it:n) {
                if (it.first>=nums[i]) {
                    break;
                }
                t = max(t, m[it.second]);
            }
            m[i] = t+1;
            n[nums[i]] = i;
            
            res = max(res, m[i]);
            
            //cout<<m[i]<<" ";
        }
        
        return res;
    }
};
