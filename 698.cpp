/*
 * 698. Partition to K Equal Sum Subsets
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all equal
 */
 
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int K) {
       // 1 <= k <= len(nums) <= 16, we can use int to store status
        int visited = 0;
        int cur = 0, count = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum/K;
        if (sum%K !=0)
            return false;
        sort(nums.rbegin(), nums.rend());    // <<<<<<-------- sort from larger to smaller 
        return helper(nums, K, visited, cur, target);
    }
    
    bool helper(const vector<int>& nums, int k, int visited, int cur, int target) {
        //cout << cur<<" "<<k<<endl;
        if (k==0) {
            return visited == (1<<nums.size())-1;
        }
        for (int i=0; i<nums.size(); ++i) {
            int t = cur+nums[i];
            if (visited & (1<<i)) {
                continue;
            }
            if (t > target) {       //<<<<<<<<-------------
                break;                 
            }
            int temp = visited | (1<<i);
            if (t == target && helper(nums, k-1, temp, 0, target)) {
                    return true;
            } else if (helper(nums, k, temp, t,target)) {
                return true;
            }
        }
        return false;
        
    }
};
