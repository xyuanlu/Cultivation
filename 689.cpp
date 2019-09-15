/*
 * 689. Maximum Sum of 3 Non-Overlapping Subarrays
 * 
 * In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.
 *
 * Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.
 *
 * Return the result as a list of indices representing the starting position of each interval
 * (0-indexed). If there are multiple answers, return the lexicographically smallest one.
 *
 */
 
 class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        /*
         * m[i][j] -> the max value we can get when jth group starts at i
         */
        vector<int> res;
        vector<int> preSum = {0};
        vector<vector<int>> m(nums.size(), vector<int>(4, 0));
        vector<vector<int>> p(nums.size(), vector<int>(4, 0));
        
        int resIdx, resMax = 0;
        
        // Prefix Sum
        int s = 0;
        for(int i=0; i<nums.size(); ++i) {
            s += nums[i];
            preSum.push_back(s);
            //cout<<s<<" ";
        }
        //cout<<endl;
        
        for (int j=1; j<=3; ++j) {
            for (int i=0; i+(3-j+1)*k<=nums.size(); ++i) {
                if(i<(j-1)*k)
                    continue;
                // sum of nums[i] -> sum[i+k-1].
                int t = preSum[i+k] - preSum[i];
                int prev = 0;
                for(int h=max(0,(j-2)*k); h<=i-k; ++h) {
                    if (m[h][j-1] > prev) {
                        prev = m[h][j-1];
                        p[i][j] = h;
                    }
                }
                //cout<<i<<" "<<j<<" "<<prev<<" "<<t<<endl;
                m[i][j] = prev + t;
                if (j==3) {
                    if(m[i][j] > resMax) {
                        resMax = m[i][j];
                         resIdx = i;
                    }
                }
            }
        }
        
        /*for (int i=0; i<nums.size(); ++i) {
            for (int j=1; j<=3; ++j) {
                cout<<m[i][j]<<' ';
            }
            cout<<endl;
        }*/
        
        res = {p[p[resIdx][3]][2], p[resIdx][3], resIdx};
        return res;
    }
};
