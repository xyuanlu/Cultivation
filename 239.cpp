/*
 * 239. Sliding Window Maximum
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
         * -- store only elements that need to be considered. --
         * 
         * If for current window, the max value is at idx 1
         * We do not need to consider all values < num[i] before i. 
         * They will never be a max in anywindow.
         * 
         * Always keep dequeue a non-increasing queue
         *
         *   -- When pushing an elemt into the queue, pop back untill
         *      the queue is still a non-increasing queue.
         *
         * The front element will always be the largest element
         * in the window.
         */
     
        int l=0, r = l;
        deque<int> q;
        vector<int> res;
        while(r<nums.size()) {
            while(!q.empty() && q.back() < nums[r]) {
                q.pop_back();
            }
            q.push_back(nums[r]); 
            //cout<<l<<" "<<r<<endl;
            if(l == r-k+1) {
                res.push_back(q.front());
                if(nums[l] == q.front()) {
                    q.pop_front();
                } 
                ++l;
            }
            ++r;
        }
        return res;
    }
};
