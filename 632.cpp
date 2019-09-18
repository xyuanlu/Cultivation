/*
632. Smallest Range Covering Elements from K Lists

  You have k lists of sorted integers in ascending order.
  Find the smallest range that includes at least one number from each of the k lists.

  We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
  Example 1:

  Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
  Output: [20,24]
  Explanation: 
  List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
  List 2: [0, 9, 12, 20], 20 is in range [20,24].
  List 3: [5, 18, 22, 30], 22 is in range [20,24].


  Note:

  The given list may contain duplicates, so ascending order means >= here.
  1 <= k <= 3500
  -105 <= value of elements <= 105.

*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        /* 
         * Preprosessing + 2 pointer and min window
         * The same as Min subarray with K distinct etc..
         * Where k is the number of arrays we have.
         */

        
        int k = nums.size();
        unordered_map<int, vector<int>> m;
        vector<int> a;
        for(int i=0; i<nums.size(); ++i) {
            for(int j=0; j<nums[i].size(); ++j) {
                m[nums[i][j]].push_back(i);   // We have nums[i][j] at ith list
            }
        }
        for(auto it:m) {
            a.push_back(it.first);
        }
        sort(a.begin(), a.end());
        
        int resSize = 10000000;
        vector<int> res;
        
        int count = 0, l = 0, r = l, start = 0;
        vector<int> mm(k, 1);  // we need 1 from rach list
        while (r<a.size()) {
            // we met m[r] update mm and count
            //cout<<l<<" "<<r<<endl;
            for(int listN: m[a[r]]) {
                if(mm[listN] >0) {
                    count++;
                }
                mm[listN]--;
            }
            //cout<<count<<endl;
            while(count == k && l<=r) {
                if(a[r]-a[l]+1 < resSize) {
                    //cout<<l<<" "<<a[l]<<" "<<r<<" "<<a[r]<<endl;
                    res = {a[l], a[r]};
                    resSize = a[r]-a[l]+1;
                }
                for(int listN: m[a[l]]) {
                    if(mm[listN]==0) {
                        count--;
                    }
                    mm[listN]++;
                }
                ++l;
            }
            ++r;
        }
        return res;
    }
};
