/*
 * 350. Intersection of Two Arrays II
 * Given two arrays, write a function to compute their intersection.
 * 
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 */
 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for(auto i:nums1) {
            m[i]++;
        }
        for(auto i:nums2) {
            if(m.find(i) != m.end()) {
                res.push_back(i);
                m[i]--;
                if(m[i]==0) {
                    m.erase(i);
                }
            }
        }
        return res;
    }
};
