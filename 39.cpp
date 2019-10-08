/*
 * 39. Combination Sum
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number
 * (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of times.
 */
 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // BT
        
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(candidates, temp, target, 0, res);
        return res;
        
    }
    
    void helper(vector<int>& candidates, vector<int>& temp, int target,
                int idx, vector<vector<int>>& res) {
        if (target ==0) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx; i<candidates.size(); ++i) {
            if (target-candidates[i]>=0) {
                temp.push_back(candidates[i]);
                helper(candidates, temp, target-candidates[i], i, res);
                temp.pop_back();
            }
        }
        // we are not going backward........ 
    }
};
