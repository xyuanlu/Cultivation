/*
 * 261. Graph Valid Tree
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes),
 * write a function to check whether these edges make up a valid tree.
 */
 
class Solution {
public:
    class UF {
    public:
        vector<int> n;
        vector<int> c;
        
        UF(int a) {
            for (int i=0; i<a; ++i) {
                n.push_back(i);
                c.push_back(1);
            }
        }
        
        int findP(int a) {
            int res = n[a];
            if (res !=a) {
                res = findP(res); 
            }
            n[a] = res;
            return res;
        }
        
        bool isUnited(int a, int b) {
            if (findP(a) == findP(b)) {
                return true;
            }
            else
                return false;
        }
        
        bool merge(int a, int b) {
            if (isUnited(a, b)) {
                return false;
            }
            int aa = findP(a);
            int bb = findP(b);
            int ca = c[aa];
            int cb = c[bb];
            
            if (ca<cb) {
                n[aa] = bb;
                cb += ca;
            } else {
                n[bb] = aa;
                ca += cb;
            }
            return true;
        }
        
    };
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // no loop or single point in the graph
        
        UF uf(n);
        
        for (int i=0; i<edges.size(); ++i) {
            if(!uf.merge(edges[i][0], edges[i][1])) {
                return false;
            }
        }
        
        int u = 0;
        for(int i=0; i<n; ++i) {
            if(uf.n[i] == i) {
                u++;
            }
        }
        
        return u==1;
    }
};
