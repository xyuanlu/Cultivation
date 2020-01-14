/*
 * 1300. Sum of Mutated Array Closest to Target
 */
 
 class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        map<int,int> refMap;
        int sum;
        for(int i=0; i<arr.size(); ++i) {
            refMap[arr[i]] ++;
            if (sum<target)
                sum += arr[i];
        }
        
        
        int l = refMap.begin()->first;
        int r = refMap.rbegin()->first;
        if (sum < target) {
            return r;
        }
        if (target < l) {
            return target/arr.size();
        }
        l = target/arr.size();
        int min = INT_MAX, res = l;
        r++;
        while(l+1<r) {
            int m = l + (r-l)/2;
            int temp = helper(refMap, m);
            if (abs(temp-target) < min) {
                min = abs(temp-target);
                res = m;
            }
            //cout<<m<<" "<<temp<<" "<<target<<endl;
            if (temp < target) {
                l = m;
            } else {
                r = m;
            }
        }
        
        int temp = helper(refMap, l);//cout<<temp<<endl;
        if (abs(temp-target) <= min) {
            min = abs(temp-target);
            res = l;
        }
        
        return res;
    }
    
    // sum after change all number >n tp n
    int helper(map<int,int>& refMap, int n) {
        int res = 0;
        for(auto &it:refMap) {
            if (it.first<n) {
                res += it.first * it.second;
            } else {
                res += n * it.second;
            }
        }
        return res;
        
    }
    
};

