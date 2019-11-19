/*
 * 1192. Critical Connections in a Network
 * 
 */
 
// https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
class Solution {
public:
    // Each node has a id, and a min id node it can see 
    // Nodes in a circle can see the same same min-value id node
    // If an edge from U to v, where id[u] < low[v]
    // then they are not in a circle -> it is a critical connect
    
    int t = 0;
    vector<int> low, id;
    unordered_map<int, vector<int>> edges;
    vector<vector<int>> res;
    vector<bool> visited;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low = vector<int>(n);
        id = vector<int>(n);
        visited = vector<bool>(n);
        
        for(int i=0; i<connections.size(); ++i) {
            edges[connections[i][0]].push_back(connections[i][1]);
            edges[connections[i][1]].push_back(connections[i][0]);
        }
        
        helper(0, -1);
        return res;
    }
    
    void helper(int cur, int prev) {
        visited[cur] = true;
        t++;
        low[cur] = t;
        id[cur] = t;
        
        for(int u : edges[cur]) {
            if (u == prev) 
                continue;
            // we have a loop if visited if visited[u]
            if (!visited[u]) {
                helper(u, cur);
            } 
            // now the low[u] has updated value
            low[cur] = min(low[u], low[cur]);
            if (low[u] > id[cur]) {
                res.push_back({cur, u});
            }
        }
        
        
    }
};
