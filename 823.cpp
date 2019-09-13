/*
 * 823. Binary Trees With Factors
 * 
 * Given an array of unique integers, each integer is strictly greater than 1.
 * We make a binary tree using these integers and each number may be used for any number of times.
 * Each non-leaf node's value should be equal to the product of the values of it's children.
 * How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.
 */
 
 
 class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int MOD = 1000000007;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> idxMap;
        vector<int> memo(nums.size(), 1);
        
        auto add = [&] (int l, int r) {
            return (l+r) % MOD;
        };
        auto mul = [&] (int l, int r) {
            long long ll = l;
            long long rr = r;
            return (ll * rr)% MOD;
        };
        
        int res = 0;
        for (int i=0; i<nums.size(); ++i) {
            idxMap[nums[i]] = i;
        }
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i-1; j>=0; --j) {
                //cout<<i<<" "<<j<<endl;
                auto it = idxMap.find(nums[i]/nums[j]);
                if(it !=idxMap.end() && nums[i]%nums[j] == 0) {
                    memo[i] = add(memo[i], mul(memo[j], memo[it->second]));
                }
            }
            res = add(res, memo[i]);
            //cout<<i<<": "<<memo[i]<<endl;
        }
        return res;
    } 
};
