/*
 *  11. Container With Most Water
 *  Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 *  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 *  which together with x-axis forms a container, such that the container contains the most water.
 */
 
 
 class Solution {
public:
    int maxArea(vector<int>& nums) {
        int res = 0;
        int i=0, j=nums.size()-1;
        while(i<j) {
            res = max(res, min(nums[i], nums[j]) * (j-i));
            if(nums[i] > nums[j])
                j--;
            else i++;
        }
        return res;
    }
};
