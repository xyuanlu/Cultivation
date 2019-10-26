/*
 * 334. Increasing Triplet Subsequence
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 *
 * Formally the function should:
 * 
 *  Return true if there exists i, j, k
 *  such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 *  Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
 */
 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // size of res <=2, size of can <= 1
        deque<int> res, can;
        
        for(int i=0; i<nums.size(); ++i) {
            int t = nums[i];
            if (res.size()==2 && nums[i]>res[1]) {
                return true;
            }
            if (res.size()==0 || (res.size()==1 && t>res[0])) {
                res.push_back(t);
            } 
            else if ( (res.size()==1 && t<res.back()) || 
                      (res.size()==2 && t>res[0] && t<res[1]) )  {
                res.pop_back();
                res.push_back(t);
            }
            else if (res.size()==2 && t<res[0]) {
                if(can.empty())
                    can.push_back(t);
                else if (!can.empty() && t>can[0]) {
                    res = can;
                    res.push_back(t);
                    can = deque<int>();
                } else {
                    can[0] = t;
                }
            }
            
            /*for(auto i:res) {
                cout<<i<<" ";
            }
            cout<<":   ";
            for(auto i:can) {
                cout<<i;
            }
            cout<<endl;*/
        }
        
        return false;
    }
};
