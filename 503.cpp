/*
 * 503. Next Greater Element II
 * Given a circular array (the next element of the last element is the first element of the array),
 * print the Next Greater Number for every element. The Next Greater Number of a number x is the first
 * greater number to its traversing-order next in the array, which means you could search circularly to
 * find its next greater number. If it doesn't exist, output -1 for this number.
 */
 
 class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
         * Keep a increasing stack.
         * Traverse from rnd to begin.
         * current result is stack.top
         * Push to stack if current value < stack.top
         * or pop until cur<top or stack is empty
         * -> any value that is less than current
         *    can not be previous value's result
         */
        vector<int> res;
        stack<int> memo;
        int globalMax = INT_MIN;
        int curRes = -1;
        for(int i=nums.size()-1; i>=0; --i) {
            globalMax = max(globalMax, nums[i]);
            
            while(!memo.empty() && nums[i] >= memo.top()) {
                memo.pop();
            }
            if(memo.empty()) {
                curRes = -1;
            } else {
                curRes = memo.top();
            }
            res.push_back(curRes);
            memo.push(nums[i]);
        }
        reverse(res.begin(), res.end());
        cout<<endl;
        
        for(int i=nums.size()-1; i>=0; --i) {
            if (nums[i] == globalMax)
                break;
            while(!memo.empty() && nums[i] >= memo.top()) {
                memo.pop();
            }
            if(memo.empty()) {
                curRes = -1;
            } else {
                curRes = memo.top();
            }
            res[i]=curRes;
            memo.push(nums[i]);
        }
        return res;
    }
};
