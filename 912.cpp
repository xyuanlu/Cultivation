/*
 * 912. Sort an Array
 */
 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // lets do a quick sort
        helper(nums, 0, nums.size()-1);
        return nums;
    }
    
    void helper(vector<int>& nums, int s, int e) {
        if (s>=e) {
            return;
        }
        int pivot = nums[e];
        int l=s, r=e;
        while(l<r) {
            if (nums[l]<=pivot) {
                ++l;
                continue;
            }
            if (nums[r]>=pivot) {
                --r;
                continue;
                
            }
            swap(nums, l, r);
            //++l;
            //--r;
        }
        swap(nums, l, e);
        /*cout<<"p "<<pivot<<", e "<<e<<endl;
        for(int i:nums) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        
        helper(nums, s, l-1);
        helper(nums, l+1, e);
    }
    
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};
