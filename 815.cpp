/*
 *  We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever.
 *  For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the
 *  sequence 1->5->7->1->5->7->1->... forever.
 *  We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by
 *  buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.
 *
 *  BFS 
 *   1. Route be the node not stops
 *   2. Track route in visited
 */
 
 class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S==T)
            return 0;
        /* BFS where bus route as node
         * R1 and R2 are connected if they share same stop
         * we track visited route (not stops)
         */
        unordered_map<int, unordered_set<int>> r2s;
        unordered_map<int, unordered_set<int>> s2r;
        for(int i=0; i<routes.size(); ++i) {
            r2s[i] = unordered_set<int>(routes[i].begin(), routes[i].end());
            for(int s:routes[i]) {
                s2r[s].insert(i);
            }
        }
        
        queue<int> q, t;
        set<int> visited;
        int res = 1;
        bool found = false;
        // Push first nodes (routes that can reach start station to queue)
        for(auto r:s2r[S]) {
            //cout<<"init:"<<r<<" ";
            visited.insert(r);
            q.push(r);
        }
        //cout<<endl;
        
        while(!q.empty()) {
            int curR = q.front();
            //cout<<"curR "<<curR<<" "<<endl;
            //visited.insert(curR);
            q.pop();
            // Iterate through all stations this route can reach
            for(auto s:r2s[curR]) {
                if(s == T) {
                    found = true;
                    return res;
                }
                // for station s, iterate through all routes that can access this s
                for(auto r:s2r[s]) {
                    if(visited.find(r) != visited.end()) continue;
                    //cout<<"next"<<r<<" ";
                    visited.insert(r);
                    t.push(r);
                }
            }
            if(q.empty()) {
                //cout<<"switch t:"<<t.size()<<endl;
                q = t;
                t = queue<int> {};
                ++res;
                //cout<<endl;
            } 
        }
        
        return found? res: -1;
    }
};
