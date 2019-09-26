/*
 * 347. Top K Frequent Elements
 * Given a non-empty array of integers, return the k most frequent elements.
 */
 class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Ref count + bucket sort
        unordered_map<int, int> m;
        for(int n:nums) {
            m[n]++;
        }
        
        vector<vector<int>> buckets(nums.size()+1);  // <<<<------- size()+1's bucket
        for(auto it:m) {
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> res;
        int c = 0;
        for (int i=buckets.size()-1; i>=0; --i) {
            for(int j=0; j<buckets[i].size(); ++j) {
                if(c<k) {
                    res.push_back(buckets[i][j]);
                    c++;
                } 
                if(c>k) {
                    return res;
                }
            }
        }
        return res;
    }
};
