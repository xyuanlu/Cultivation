/*
 * 659. Split Array into Consecutive Subsequences
 *
 * Given an array nums sorted in ascending order, return true if and only if you can split
 * it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.
 */
 
class Solution {
public:
    struct cmp {
        bool operator()(vector<int> v1, vector<int> v2) const{
            return v1.size()>v2.size();
        }
    };
    
    using pq=priority_queue<vector<int>, vector<vector<int>>, cmp>;
    bool isPossible(vector<int>& nums) {
        // the end item of vector is the key
        unordered_map<int, pq> m;    
        //<<------ no need to keep the vectors, only length is needed
        for(int i=0; i<nums.size(); ++i) {
            //cout<<nums[i]<<endl;
            if (m.find(nums[i]-1) == m.end()) {
                m[nums[i]].push(vector<int>{nums[i]});
            } else {
                vector<int> t = m[nums[i]-1].top();
                m[nums[i]-1].pop();
                if (m[nums[i]-1].size()==0) {
                    m.erase(nums[i]-1);
                }
                t.push_back(nums[i]);
                m[nums[i]].push(t);
            }
        }
        
        for(auto &it:m) {
            while(it.second.size()!=0) {
                if (it.second.top().size()<3) {
                    return false;
                } else {
                    it.second.pop();
                }
            }
        }
        
        return true;
    }
};
