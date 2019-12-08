/*
 * 75. Sort Colors
 * sort [2,0,2,1,1,0] -> [0,0,1,1,2,2]
 */
 
 class Solution {
public:
    void sortColors(vector<int>& nums) {
        // n is te boundry of 0's, m is the boundry of 2's
        int n=0, m=nums.size()-1;
        while(n<nums.size() && nums[n]==0)
            ++n;
       // cout<<n<<endl;
        while(m>=n && nums[m]==2)
            --m;
        int idx = n;
        while(idx<=m) {
            //cout<<idx<<" "<<n<<" "<<m<<endl;
            if (nums[idx]==0) {
                nums[idx] = nums[n];
                nums[n] = 0;
                while(n<nums.size() && nums[n]==0) ++n;
                idx=n;             //<-----------
            } else if (nums[idx]==2) {
                nums[idx] = nums[m];
                nums[m] = 2;
                while(m>=n && nums[m]==2) --m;
            }
            if (nums[idx]==1)
                ++idx;
        }
    }
};
