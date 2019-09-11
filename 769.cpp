/*
 * 769. Max Chunks To Make Sorted
 *  Given an array arr that is a permutation of [0, 1, ..., arr.length - 1],
 *  we split the array into some number of "chunks" (partitions), and individually sort each chunk.
 *  After concatenating them, the result equals the sorted array.
 *
 *  What is the most number of chunks we could have made?
 *
 * Exp 1:
 *  Input: arr = [4,3,2,1,0]
 *  Output: 1
 *
 * Exp 2;
 *  Input: arr = [1,0,2,3,4]
 *  Output: 4
 */
 
 
 class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        return helper(0, nums);
    }
    int helper(int begin, const vector<int> & nums) {
        if (begin == nums.size()) return 0;
        int curMax = nums[begin];
        int i=begin;
        for (i=begin; i<=curMax && i<nums.size(); ++i) {
            curMax = max(nums[i], curMax);
        }
        return 1 + helper(i, nums);
    }
};
