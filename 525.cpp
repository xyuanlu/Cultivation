/*
 * 525. Contiguous Array
 * Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
 */
 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        
        // pair of (0's count, 1's count) -> idx
        // we won;t have duplicate key in this map    ->> LTE
        
        // key: d : c0-c1  -> idx
        unordered_map<int, int> m;
        int c0 = 0, c1 = 0; 
        
        for(int i=0; i<nums.size(); ++i) {
            if (nums[i]==0) {
                c0++;
            } else {
                c1++;
            }
            if (c1 == c0) {
                res = i+1;
                continue;
            }
            auto it = m.find(c0-c1);
            if (it!=m.end()) {
                res = max(res, i-it->second);
            } else {
                m[c0-c1] = i;
            }
            
        }
        
        return res;
    }
};
