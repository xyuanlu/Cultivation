/*
 * 684. Redundant Connection
 * In this problem, a tree is an undirected graph that is connected and has no cycles.
 * Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there
 * are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v]
 * should be in the same format, with u < v.
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int N = edges.size();
        UF uf(N);
        
        for(int i=0; i<N; ++i) {
            int a = edges[i][0]-1;
            int b = edges[i][1]-1;
            if (!uf.unite(a, b)) {
                return edges[i];
            }
        }
        
        return res;
    }
    
};









