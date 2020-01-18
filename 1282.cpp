/*
 * 1282. Group the People Given the Group Size They Belong To
 */
 
 class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        // number of isze and the result;
        unordered_map<int, vector<int>> m;
        
        for(int i=0; i<groupSizes.size(); ++i) {
            m[groupSizes[i]].push_back(i);
            if (m[groupSizes[i]].size()==groupSizes[i]) {
                res.push_back(m[groupSizes[i]]);
                m[groupSizes[i]] = vector<int>();
            }
        }
        return res;
    }
};
