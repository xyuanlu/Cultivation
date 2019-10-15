/*
 * 254. Factor Combinations
 * Numbers can be regarded as product of its factors. For example,
 *
 * 8 = 2 x 2 x 2;
 *   = 2 x 4.
 * Write a function that takes an integer n and return all possible combinations of its factors.
 */
 
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        
        for(int i=2; i*i<=n; ++i) {
            if (n%i==0) {
                res.push_back(vector<int>{i, n/i});
                vector<vector<int>> temp = getFactors(n/i);
                for(int j=0; j<temp.size(); ++j) {
                   // cout<<i<<" "<<temp[j][0]<<endl;
                    if (temp[j][0]<i)
                        continue;
                    vector<int> t = {i};
                    t.insert(t.end(), temp[j].begin(), temp[j].end());
                    res.push_back(t);
                }
            }
        }
        
        return res;
    }
};
