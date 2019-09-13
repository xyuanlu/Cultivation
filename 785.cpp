/*
 * 785. Is Graph Bipartite?
 *
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split it's set of nodes into two independent
 * subsets A and B such that every edge in the graph has one node in A and another node in B.
 *
 * The graph is given in the following form: graph[i] is a list of indexes j for which the edge between
 * nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges
 * or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
 */
 class Solution {
    /*
     * Using coluring.
     * Starting with a point and sign it with a color. 
     * All it unvisited neighbor will be asign to another color.
     * If its neighboor is already assigned to the same color then return false.
     * A graph can only have one (and a symantric) solution. 
     * So the starting point does not matter
     *
     */
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // -1 for unvisited, 0 for color 1 and 1 for color2.
        vector<int> color(graph.size(), -1);
        queue<int> q;
        for(int i=0; i<graph.size(); ++i) {
            if(color[i] != -1){
                continue;
            }
            color[i] = 0;
            q.push(i);
            while(!q.empty()) {
                int t = q.front();
                int tc = color[t];
                q.pop();
                //cout<<"t "<<t<<endl;
                for(int n:graph[t]) {
                    //cout<<n<<" "<<color[n]<<endl;
                    if(color[n] == color[t])
                        return false;
                    else if (color[n]==-1) {   // unvisited.
                        color[n] = (color[t]+1)%2;
                        q.push(n);
                    } else {                   // not the same color.
                        continue;
                    }
                }
            }
        }
        //for(auto i:color) {cout<<i<<" ";}
        return true;
    }
    
};
 
