/*
 * 743. Network Delay Time
 *  The Dijkstra's algorithm in OSPF 
 * https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
 */


class Solution {
public:
    class P{
    public:
        int n;
        int d;
        
        P(int nn, int dd): n(nn), d(dd) {};
        
        // we need to sort P in min heap 
        bool operator<(P pp) const{
            return d > pp.d;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // OSPF
        vector<int> dis(N+1, INT_MAX);
        vector<bool> visited(N+1, false);
        
        // build the edges table
        unordered_map<int, vector<P>> m;
        for(int i=0; i<times.size(); ++i) {
            m[times[i][0]].push_back(P{times[i][1], times[i][2]});
        }
        
        dis[K] = 0;
        
        priority_queue<P> pq;
        pq.push(P(K, 0));
        
        while(!pq.empty()) {
            P t = pq.top();
            pq.pop();
            for(int i=0; i<m[t.n].size(); ++i) {
                P pp = m[t.n][i];
                if (!visited[pp.n] && dis[pp.n]>t.d+pp.d) {
                    pq.push({pp.n, t.d+pp.d});
                    dis[pp.n] = t.d+pp.d;
                }
            }
        }
        int res = 0;
        for(int i=1; i<=N; ++i) {
            res = max(res, dis[i]);
            if (dis[i] == INT_MAX)
                return -1;
        }
        return res;
    }
};
