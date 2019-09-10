/*
 * 46. Permutations
 *  Given a collection of distinct integers, return all possible permutations.
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> visited;
        vector<int> temp;
        
        helper(nums, res, visited, temp);
        return res;
    }
    
    void helper(const vector<int>& nums, vector<vector<int>>& res,
           unordered_set<int>& visited, vector<int>& temp) {
        if(temp.size() == nums.size()) {
            res.push_back(vector<int>{temp});
            return;
        }
        for(int n:nums) {
            if(visited.find(n) == visited.end()) {
                temp.push_back(n);
                visited.insert(n);
                helper(nums, res, visited, temp);
                temp.pop_back();
                visited.erase(n);
            }
        }
        
    }
};
