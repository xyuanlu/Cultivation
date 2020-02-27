class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> temp;

        dfs(res, temp, visited, nums);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &temp, vector<bool> &visited, const vector<int> &nums) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i=0; i<visited.size(); ++i) {
            if (visited[i] == false) {
                if(i>0 && nums[i] == nums[i-1] && visited[i-1] == false)
                    continue;
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(res, temp, visited, nums);
                visited[i] = false;
                temp.pop_back();
                /*int j=i;
                for (j=i; j<nums.size()-1;) {
                    if (nums[j+1] !=nums[i])
                        break;
                    ++j;
                }
                i=j;*/
            }
        }

    }
}; 

