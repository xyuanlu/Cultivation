/*
* 787. Cheapest Flights Within K Stops
*
*  Optimal sub problem.... Yuanyuan!! what are you thinking?!
*/

class Solution {
public:
    class P{
    public:
        int n;
        int val;
    };
    
    // node -> vector<pair<dest, cost>>
    unordered_map<int, vector<P>> m;
    // dp[i] is the lowest cost from node i to dest
    unordered_map<int, unordered_map<int, int>> dp;
    vector<bool> v;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        v = vector<bool>(n, false);
        
        for(int i=0; i<flights.size(); ++i) {
            m[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            //m[flights[i][1]].push_back({flights[i][0], flights[i][2]});
        }
        int res = helper(src, dst, 0, K+1);
        return res==INT_MAX? -1: res;
    }
    
    int helper(int cur, int dst,  int step, int K) {
        if (cur == dst) {
            //cout<<cost<<endl;
            return 0;
        }
        if (step == K) {
            return INT_MAX;
        }
        if (dp[cur].find(step) != dp[cur].end()) {
            return dp[cur][step];
        }
        v[cur] = true;
        int res = INT_MAX;
        for(int i=0; i<m[cur].size(); ++i) {
            if(v[m[cur][i].n]) continue;
            int temp = helper(m[cur][i].n, dst,step+1, K);
            if (temp == INT_MAX) continue;
            res = min(res, m[cur][i].val + temp);
            //v[m[cur][i].n] = false;
        }
        dp[cur][step] = res;
        v[cur] = false;
        return res;
    }
};

