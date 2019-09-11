/*
 * 456. 132 Pattern
 *  Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj,
 *  ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers
 *  as input and checks whether there is a 132 pattern in the list.
 *
 * Exp1:
 *  [1, 2, 3, 4] -> False
 *
 * Exp2:
 *  [3, 1, 4, 2] -> True
 */
 
 class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        /*
         * 1. Compute te index of cur_min we have met
         * 2. Travel from end to begin, maintaing a stack
         *    while (top< cur_min), there is no need to 
         *    keep the top value.
         * The stack keeps track of all possible value -- 
         * the smallist of al values larger than cur_min.
         * Since cur_min is a non-decreasing array from
         * righ->left, there is no need to keep top value
         * that is smaller than cur_min.
         */
        if (nums.size() == 0) 
            return false;
        vector<int> cur_min;
        stack<int> memo;
        int temp = nums[0];
        for (int i=0; i<nums.size(); ++i) {
            temp = min(temp, nums[i]);
            cur_min.push_back(temp);
            //cout<<temp<<" ";
        }
        //cout<<endl;
        
        memo.push(nums[nums.size()-1]);
        for(int i=nums.size()-2; i>=0; --i) {
            int minMax = INT_MAX;
            while(!memo.empty() && memo.top()<=cur_min[i]) {
                memo.pop();
            }
            if (!memo.empty()) {
                minMax = memo.top();
            }
            /*if(memo.empty()) 
                cout<<"* ";
            else
                cout<<memo.top()<<" ";
            */
            //cout<<cur_min[i]<<" "<<minMax<<" "<<nums[i]<<" "<<endl;
            if (minMax > cur_min[i] && minMax<nums[i])
                return true;
            if(nums[i]<minMax)
                memo.push(nums[i]);

        }
        return false;
    }
};
