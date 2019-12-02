/*
 * 260. Single Number III
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other
 * elements appear exactly twice. Find the two elements that appear only once.
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // assume the two bits are n1 and n2
        // 1. find n1 XOR n2
        // 2. There is a bit in n1 but not in n2. -> mask2
        // 3. XOR all n in nums & mask2 !=0  -> n1
        // 4. thus we find n2.
        
        int mask1 = 0, mask2 = 1, mask3 = 0;
        
        for(int n:nums) {
            mask1 = mask1^n;
        }
       
        while((mask2 & mask1) ==0) {
             mask2 = mask2 <<1;
        }
         
        for(int n:nums) {
            if ((n & mask2) !=0) {
                mask3 = mask3 ^ n;
            }
        }
        //cout<<mask1<<" "<<mask2<<" "<<mask3<<endl;
        
        mask1 = mask1 ^ mask3;
        return {mask1, mask3};
        
    }
};
