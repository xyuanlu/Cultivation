/*
 * 229. Majority Element II
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 * Note: The algorithm should run in linear time and in O(1) space.
 */
 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cad1, cad2, c1=0, c2=0;
        
        for(int i=0; i<nums.size(); ++i) {
            if (c1==0 && cad2 != nums[i]) {
                c1++;
                cad1 = nums[i];
            } else if (cad1 == nums[i]) {
                c1++;
            } else if (c2==0) {
                c2++;
                cad2 = nums[i];
            }  else if (cad2 == nums[i]) {
                c2++; 
            } else {
                c1--;
                c2--;
            }
        }

        //cout<<cad1<<" "<<cad2<<endl;
        int cc1=0, cc2=0;
        for(int i=0; i<nums.size(); ++i) {
            if (nums[i] == cad1) ++cc1;
            if (nums[i] == cad2) ++cc2;
        }
        
        vector<int> res;
        if (cc1>nums.size()/3) {
            res.push_back(cad1);
        }
        if (cad2 != cad1 && cc2>nums.size()/3) {
            res.push_back(cad2);
        }
        return res;
    }
};
