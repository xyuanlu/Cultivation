/*
 * 78. Subsets
 *  Given a set of distinct integers, nums, return all possible subsets (the power set).
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
         * Textbook like BT question
         */
        
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums, 0, res, temp);
        return res;
    }
    
    void helper(const vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& temp) {
        if(i == nums.size()) {
            res.push_back(vector<int>(temp));
            return;
        }
        helper(nums, i+1, res, temp);
        temp.push_back(nums[i]);
        helper(nums, i+1, res, temp);
        temp.pop_back();
    }
};
