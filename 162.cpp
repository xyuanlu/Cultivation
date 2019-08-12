class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int b=0, e = nums.size(), m=0;
        while(e-b>1) {
            m = (b+e)/2;
            if(m==0 || nums[m]>nums[m-1])
                b=m;
            else
                e=m;
        }
        return b;
    }
};
