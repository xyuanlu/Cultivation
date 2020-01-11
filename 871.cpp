/*
 * 871. Minimum Number of Refueling Stops
 * 
 */
 
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int max = startFuel, idx = 0;
        int res = 0;
        priority_queue<int> pq;
        
        while(idx<stations.size() && stations[idx][0]<=max) {
            pq.push(stations[idx][1]);
            ++idx;
        }
        
        while(max<target && !pq.empty()) {
            max += pq.top();
            pq.pop();
            res++;
           // cout<<idx<<endl;
            while(idx<stations.size() && stations[idx][0]<=max) {
                pq.push(stations[idx][1]);
                ++idx;
            }
        }
        //cout<<max<<endl;
        if (max<target) return -1;
        return res;
        
    }
};
