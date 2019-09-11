/*
 *
 *
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, res, temp, visited, 0);
        return res;
    }
    
    void helper(const vector<int>& nums,  vector<vector<int>>& res, vector<int>& temp,
               vector<bool>& visited, int idx) {
        if(idx == nums.size()) {
            res.push_back(vector<int>(temp));
            return;
        }
        helper(nums, res, temp, visited, idx+1);
        // if this num is the same as privous, and previous is not selected. pass this as well
        if(idx>0 && nums[idx] == nums[idx-1] && !visited[idx-1]) {
            return;
        }
        visited[idx] = true;
        temp.push_back(nums[idx]);
        helper(nums, res, temp, visited, idx+1);
        visited[idx] = false;
        temp.pop_back();
    }
};
