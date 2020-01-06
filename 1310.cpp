/*
 * 1310. XOR Queries of a Subarray
 * Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri],
 * for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1]
 * xor ... xor arr[Ri] ). Return an array containing the result for the given queries.
 */
 
 class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> preXor;
        
        int cur = arr[0];
        preXor.push_back(cur);
        for(int i=1; i<arr.size(); ++i) {
            cur = arr[i]^cur;
            preXor.push_back(cur);
        }
        
        vector<int> res;
        for(auto &it:queries) {
            int l = it[0], r = it[1];
            if (l==0) {
                res.push_back(preXor[r]);
            } else {
                 res.push_back(preXor[r] ^ preXor[l-1]);
            }
        }
        return res;
    }
};
