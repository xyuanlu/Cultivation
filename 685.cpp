/*
 * 685. Redundant Connection II
 *
 * 1. There is one node with two indegree
 * 2. All nodes has one indegree, but there is a loop.
 * 3. {[1,2], [2,3], [3,2]}
 */
 
 class Solution {
public:
    class UF{
    public:
        vector<int> node;
        vector<int> c;
        int group;
        
        UF(int n) {
            for (int i=0; i<n; ++i) {
                node.push_back(i);
                c.push_back(i);
            }
            group = n;
        }
        
        int parent(int n) {
            int p = node[n];
            if (p != n) {
                p = parent(p);
                node[n] = p;
            }
            return p;
        }
        
        bool unite(int a, int b) {
            int aa = parent(a);
            int bb = parent(b);
            if (aa == bb) {
                return false;
            }
            if (c[aa] < c[bb]) {
                node[aa] = bb;
                c[bb] += c[aa];
            } else {
                node[bb] = node[aa];
                c[aa] += c[bb];
            }
            group--;
            return true;
        }
        
    };
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> res, candidate;
        int N = edges.size(), resIdx = -1;;
        UF uf(N);
        //vector<bool> v(N+1, false);
        
        //find node with 2 indegres;
        unordered_map<int, int> e;
         for(int i=0; i<N; ++i) {    
            if (e.find(edges[i][1]) == e.end()) {
                e[edges[i][1]] = edges[i][0];
            } else {
                 cout<<i<<endl;
                 resIdx = i;
                 res = vector<int>{edges[i]};
                 candidate = vector<int> {e[edges[i][1]], edges[i][1]};
                 break;
             }
         }
        //cout<<res.size()<<" "<<candidate.size()<<endl;
        
        //cout<<resIdx<<endl;
        for(int i=0; i<N; ++i) {
            if(i==resIdx) {
                continue;
            }
            int a = edges[i][0]-1;
            int b = edges[i][1]-1;
            if (!uf.unite(a, b) ) {
                if (resIdx!=-1) {
                    // we still have loop after 'res' is found;
                    return candidate;
                } else {
                    return edges[i];
                }
                
            }
            //v[edges[i][1]] = true;
        }
        
        
        return res;
        
    }
    
    /*
    We can not use this approach since 
    
    "If there are multiple answers, return the answer that occurs last in the given 2D-array."
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // a node can not be visited wtice (it has two parents)
        // nor can it be in visiting state (loop in directed graph)
        
        int N = edges.size();
        unordered_map<int, vector<int>> e;
        for(auto &it:edges) {
            e[it[0]].push_back(it[1]);
        }
        
        
        // 0 for unvisited, 1 for visiting and 2 for visited.
        // The nodes are indexted by 1~N, we are not uding the
        // idx '0' in this map
        vector<int> visited(N+1, 0);
        vector<int> res;
        
        for(int i=1; i<=N; ++i) {      
            if (visited[i]==0) {
                cout<<i<<endl;
                if(!helper(e, i, visited, res))
                    break;
            }
        }
        
        return res;
    }
    
    bool helper(unordered_map<int, vector<int>> e, int cur,
                vector<int>& visited, vector<int>& res) {
        assert(visited[cur] ==0);
        
        visited[cur] = 1;
        for(int i=0; i<e[cur].size(); ++i) {
            if (visited[e[cur][i]] !=0) {
                res = {cur, e[cur][i]};
                return false;
            }
            if (!helper(e, e[cur][i], visited, res)) {
                return false;
            }
        }
        visited[cur] = 2;
        return true;
    }
    */
};
