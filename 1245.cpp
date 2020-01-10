/*
 * 1245. Tree Diameter
 * 
 * Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.
 *
 * The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between
 * nodes u and v.  Each node has labels in the set {0, 1, ..., edges.length}.
 */
 
class Solution {
public:
    // starting form point p, find the farest and second farest 
    // res is teh sum
    int res;
    int treeDiameter(vector<vector<int>>& edges) {
        res = 0;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<edges.size(); ++i) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(edges.size()+1, false);
        visited[0] = true;
        helper(0, m, visited);
        return res;
        
    }
    
    // return longest path starting from this node 
    int helper(int curNode, unordered_map<int, vector<int>>& m,
               vector<int>& visited) {
        int max = 0, secondMax = 0;
        //cout<<curNode<<endl;
        //visited[curNode] = true;
        for(int i=0; i<m[curNode].size(); ++i) {
            int next = m[curNode][i];
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            int d = helper(next, m, visited)+1;
            if (d>max) {
                secondMax = max;
                max = d;
            } else if (d>secondMax) {
                secondMax = d;
            }
            visited[next] = false;
        }
        //cout<<curNode<<" "<<max<<" "<<secondMax<<endl;
        res = std::max(res, max+secondMax);
        return max;
        
    }
    
    /*
    // from 0, find the most far point M
    // from M, find the farest point N,
    // m->n is res
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        for(int i=0; i<edges.size(); ++i) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        
        int res = 0;
        unordered_set<int> visited;
        visited.insert(0);
        vector<int> t = findLen(0, 0, visited, m);
        
        //cout<<t[0]<<" "<<t[1]<<endl;
        visited = unordered_set<int>(t[0]);
        vector<int> tt = findLen(t[0], 0, visited, m);
        //cout<<tt[0]<<" "<<tt[1]<<endl;
        return tt[1];
    }
    
    // node that is the farest to input, length form input to the returned node 
    vector<int> findLen(int n, int cur, unordered_set<int>& visited,
                        unordered_map<int, vector<int>>& edges) {
        //cout << " XXX " << n << " " << cur << endl;
        for (auto e : visited) {
            cout << "  - " << e << endl;
        }
        int temp = cur;
        int e = n;
        for(int i=0; i<edges[n].size(); ++i) {
            int next = edges[n][i];
            if (visited.find(next)==visited.end()) {
                visited.insert(next);
                vector<int> t = findLen(next, cur+1, visited, edges);
                if (t[1] > temp) {
                    temp = t[1];
                    e = t[0];
                    //cout<<n << " " << cur << " " << next<<" "<<temp<<endl;
                }
                visited.erase(next);
            }
        }
        
        return {e, temp};
    }*/
};
