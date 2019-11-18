/*
 * 1168. Optimize Water Distribution in a Village
 */
 
 class Solution {
public:
    // dummy node to all houses. edge weight is the cost of buiding wells.
    // Then MST
    
    //UF
    class UF {
    public:
        vector<int> nodes;
        vector<int> size;
        UF(int n) {
            for (int i=0; i<n; ++i) {
                nodes.push_back(i);
                size.push_back(1);
            }
        }
        
        int root(int a) {
            int res = nodes[a];
            if (res != a) {
                res = root(res);
            }
            nodes[a] = res;
            return res;
        }
        
        bool isU(int a, int b) {
            int aa = root(a);
            int bb = root(b);
            return aa == bb;
        }
        
        void unite(int a, int b) {
            int aa = root(a);
            int bb = root(b);
            if (aa == bb) return;
            if (size[aa] < size[bb]) {
                nodes[bb] = aa;
                size[aa] += size[bb];
            } else {
                nodes[aa] = bb;
                size[bb] += size[aa];
            }
        } 
    };
    
    class E{
    public:
        int s;
        int e;
        int w;
        
        // pq sort from large to small, we want to sort edges from small to large
        bool operator<(const E& e) const{
            return w > e.w;
        }
        
    };
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // n=0 is the dummy node
        int N = wells.size()+1;
        // vector[i] is a list of E, start point is i
        //vector<vector<E>> edges(N);
        priority_queue<E> pq;
        // dummy edges
        for(int i=0; i<wells.size(); ++i) {
            //edges[0].push_back({0, i+1, wells[i]});
            pq.push({0, i+1, wells[i]});
        }
        // all otehr edges
        for(int i=0; i<pipes.size(); ++i) {
            //edges[pipes[i][0]].push_back({
            //    pipes[i][0], pipes[i][1], pipes[i][2]});
            pq.push({
                pipes[i][0], pipes[i][1], pipes[i][2]});
        }
        
        // MST
        UF uf(N);
        int res = 0;
        while(!pq.empty()) {
            E e = pq.top();
            int a = e.s;
            int b = e.e;
            pq.pop();
            if (uf.isU(a, b)) {
                continue;
            }
            res += e.w;
            uf.unite(a, b);
        }
        return res;
    }
};
