/*
 * 40. Combination Sum II
 *
 * Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 *  
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 */
 class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        
        helper(candidates, target, temp, 0, res);
        
        return res;
    }
    
    void helper(vector<int>& candidates, int target, vector<int>& temp,
                int idx, vector<vector<int>>& res) {
        //for (auto e : temp) {
        //    cout << e << " ";
        //}
        //cout << " XXX " << idx << " " << target << endl;
        if (idx == candidates.size()) {
            if (target ==0) 
                res.push_back(vector<int>(temp));
            return;
        }
        
        if (target<0)
            return;
        
        if (temp.empty() || candidates[idx] != temp.back()) {
            helper(candidates,target, temp, idx+1, res);
        }
        temp.push_back(candidates[idx]);
        helper(candidates,target-candidates[idx], temp, idx+1, res);
        temp.pop_back();
    }
};



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        
        helper(candidates, target, temp, 0, res);
        
        return res;
    }
    
    void helper(vector<int>& candidates, int target, vector<int>& temp,
                int idx, vector<vector<int>>& res) {
        if (target ==0) {
            res.push_back(vector<int>(temp));
            return;
        }
        
        if (target<0)
            return;
        
        for(int i=idx; i<candidates.size(); ++i) {
            if (i>idx && candidates[i]==candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i], temp, i+1, res);
            temp.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // backtrack
        // similar to number of distinct subset
        
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<bool> used(candidates.size(), false);
        vector<vector<int>> res;
        helper(temp, candidates, res, used, 0, target, 0);
        return res;
    }
    
    void helper(vector<int>& temp, const vector<int>& candidates,
                vector<vector<int>>& res, vector<bool>& used, int cur,
                int target, int idx) {
        if(cur == target) {
            res.push_back(vector<int>(temp));
            return;
        }
        if (idx == candidates.size() || cur >target)
            return;
        // not useing idx
        helper(temp, candidates, res, used, cur, target, idx+1);
        // if idx is a dup and previous has not used, then we do not use
        if(idx>0 && candidates[idx]==candidates[idx-1] && 
           used[idx-1]==false) {
                return;
        }
        
        // use idx
        if(cur + candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            used[idx] = true;
            helper(temp, candidates, res, used, cur+candidates[idx], target, idx+1);
            temp.pop_back();
            used[idx] = false;
        }
    }
};
