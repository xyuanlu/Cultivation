/*
 * 373. Find K Pairs with Smallest Sums
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 *
 * Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 */

class Solution {
public:
    class Pair {
    public:
        int x;
        int y;
        Pair(int xx, int yy): x(xx), y(yy) {};
        
        bool operator<(const Pair& p) const {
            return x+y > p.x+p.y;
        }  
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Pair> pq;
        vector<vector<int>> res;
        int idx=0, max = 0;
        
        for (int i=0; i<nums1.size(); ++i) {
            idx = 0;
            while (idx<nums2.size()) {
                int sum = nums1[i] + nums2[idx];
                if (pq.size()>=k && sum>max) {
                    //cout<<max<<endl;
                    break;
                } else {
                    max = std::max(max, sum);
                }
                pq.push(Pair(nums1[i], nums2[idx]));
                idx ++;
            }
            if (i>=k)
                break;
        }
        while(k>0 && pq.size()>0) {
            res.push_back({pq.top().x, pq.top().y});
            pq.pop();
            k--;
        }
        
        return res;
        
    }
    
    
    /*vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Pair> pq;
        vector<vector<int>> res;
        
        for(int i=0; i<min(nums1.size(), nums2.size()); ++i) {
            for (int a=i; a<nums1.size(); ++a) {
                pq.push(Pair(nums1[a], nums2[i]));
            }
            for (int b=i+1; b<nums2.size(); ++b) {
                pq.push(Pair(nums1[i], nums2[b]));
            }
            if (i>=k)
                break;
        }
        
        while(k>0 && pq.size()>0) {
            res.push_back({pq.top().x, pq.top().y});
            pq.pop();
            k--;
        }
        
        return res;
    }*/
};
