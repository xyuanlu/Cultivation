/*
 * 324. Wiggle Sort II
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 */
 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Find the midium using quick select std::nth_element
        // devide the nums into 3 parts <, =, >
        // from mid->0, in even idx 0~n
        // right->mid in odd idx
        //
        // Worst NlogN, averange N
        
        int N = nums.size();
        std::nth_element(nums.begin(), nums.begin()+N/2, nums.end());
        int mid = nums[N/2];
        vector<int> m(nums.size());
        int l = 0, r = nums.size()-1;
        for(int i=0; i<nums.size(); ++i) {
            if (nums[i] <mid) m[l++] = nums[i];
            else if (nums[i] > mid) m[r--] = nums[i];
        }
        
        while(l<=r) {
            m[l++] = mid;
        }
        
        /*for(auto i:m) {
            cout<<i<<" ";
        }
        cout<<endl;
        */
        
        l = N/2 + N%2 -1, r=N-1;
        for(int i=0; i<nums.size(); ++i) {
            if (i%2==0) {
                nums[i] = m[l--];
            } else {
                nums[i] = m[r--];
            }
            
        }
    }
};
