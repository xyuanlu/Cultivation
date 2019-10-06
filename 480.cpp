/*
 * 480. Sliding Window Median 
 */
 
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // large part stores in min heap, smaller part stores
        // in max heap
        // The size of min heap should always be
        // <(k is odd) or = (k is even) to max heap.
        
        
        multiset<int> minHp;
        multiset<int, greater<int>> maxHp;
        
        vector<double> res;
        int l=0, r=0;
        
        //maxHp.insert(nums[r]);
        //r++;
        
        while (r<nums.size()) {
            //cout<<r<<" "<<l;
            if (nums[r]<= *maxHp.begin()) {
                //cout<<"insert: "<< nums[r]<<endl;
                maxHp.insert(nums[r]);
            } else {
                minHp.insert(nums[r]); 
            }
            
            //cout<<" "<<maxHp.size()<<" "<<minHp.size()<<endl;
            
            if (maxHp.size() > minHp.size()+1) {
                int t = *maxHp.begin();
                maxHp.erase(maxHp.lower_bound(t));
                minHp.insert(t);
            } else if (maxHp.size() < minHp.size()) {
                int t = *minHp.begin();
                minHp.erase(minHp.lower_bound(t));
                maxHp.insert(t);
            }
            
            if(r-l+1 == k) {
                // Compute the mid
                if (k%2 ==0) {
                    long double d = ((double)*maxHp.begin() + (double)*minHp.begin())/2;
                    res.push_back(d);
                } else {
                    //cout<<maxHp.size()<<endl;
                    res.push_back(*maxHp.begin());
                }
                // incrase l idx.
                if (nums[l]<= *maxHp.begin()) {
                    maxHp.erase(maxHp.lower_bound(nums[l]));
                } else {
                    minHp.erase(minHp.lower_bound(nums[l]));
                }
                ++l;
            }
            ++r;
        }
        
        return res;
    }
};
