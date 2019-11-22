/*
 * 280. Wiggle Sort
 */
 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool vally = true;
        int i=0, j=i+1;
        while(j<nums.size()) {
            if ((vally && nums[i] >nums[j]) || (!vally && nums[i] < nums[j]))  {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            ++i;
            ++j;
            vally = !vally;
        }
    }
};
