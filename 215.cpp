/*
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 *Example 1:
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * Example 2:
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
         * This is a text book example like question. 
         * - std::sort    -> T: O(NlogN)                ->  S: O(1)
         * - heap         -> T: O(NlogK)                ->  S: O(k)
                          -> T: O(N + KlogN)            ->  S: O(N)
         * - QuickSelect  -> T: O(N) avg, O(N^2) worse  ->  S: O(1)   
         */
        
        // ---- sort - 4 ms ----
        /*sort(nums.begin(), nums.end());
        return nums[nums.size()-k];*/
        
        
        // ---- min heap ----
        /*use a min heap to store top K largest element  - 12 ms */
        /*priority_queue<int, vector<int>, std::greater<int>> pq;
        for(int i:nums) {
            pq.push(i);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();*/

        /*Push all elements into heap and pop K-1. Return pq.top() */
        //initilize a heap by popping one at a time take O(NlogN) - 16ms
        // https://en.wikipedia.org/wiki/Binary_heap#Building_a_heap 
        /*
        priority_queue<int> pq;
        for(int i:nums) {
            pq.push(i);
        }*/
        // Inilializing a heap from all items at once, O(N) - 12ms
        /*priority_queue<int> pq(std::less<int>(), nums);
        while(k>1) {pq.pop(); k--;}
        return pq.top();*/
        
        
        // ---- quickSelect ---- 8ms
        int res = quickSelect(nums, 0, nums.size()-1, nums.size()-k);
        return res;
        
    }
    
    int quickSelect(vector<int>& nums, int l, int r, int K) {
        if(l>=r) {
            cout<<l<<endl;
            return nums[l];
        }
        int p = l + (r-l)/2;
        int k = partition(nums, l, r, p);
        /*cout<<l<<" "<<r<<" "<<k<<": ";
        for(auto i:nums) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        if (k==K) {
            return nums[k];
        }
        if (k<K) {
            return quickSelect(nums, k+1, r, K);
        }
        else 
            return quickSelect(nums, l, k-1, K); 
    }
    
    int partition(vector<int>& nums, int l, int r, int p) {
        int pivot = nums[p];
        swap(nums, p, r);
        int startIdx = l;
        for(int i=startIdx; i<r; ++i) {
            if(nums[i] <= pivot) {
                swap(nums, startIdx, i);
                startIdx++;
            }
        }
        
        swap(nums, r, startIdx);
        return startIdx;
    }
    
    void swap(vector<int>& nums, int l, int r) {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
    
};
