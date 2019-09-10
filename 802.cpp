/*
 * 802. Find Eventual Safe States
 *
 *  In a directed graph, we start at some node and every turn, walk along a directed edge of the graph. 
 *  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
 *
 *  Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node. 
 *  More specifically, there exists a natural number K so that for any choice of where to walk, we must have
 *  stopped at a terminal node in less than K steps.
 *
 *  Which nodes are eventually safe?  Return them as an array in sorted order.
 *
 *  The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph. 
 *  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a
 *  directed edge of the graph.
 *
 *  Example:
 *    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 *    Output: [2,4,5,6]
 */


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        /*
         * Find all nodes in loops in the graph.
         *  -> visited<int> with visiting state.
         */
        vector<int> res;
        // 0 for unvisited, 1 visiting, 2 visited.
        unordered_map<int, int> visited;
        for(int i=0; i<graph.size(); ++i) {
            if(visited[i] ==0) {
                helper(graph, i, visited);
            }
        }
        for(auto& it:visited) {
            if(it.second == 2)
                res.push_back(it.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    // if I is in visiting loop, return false.
    // Only set ndoe as visited and return true iff all it's childrends ends well.
    bool helper(const vector<vector<int>>& graph, int i, 
                unordered_map<int, int>& visited) {
        //cout<<i<<endl;
        if (visited[i] == 2)
            return true;
        if (visited[i] == 1)
            return false;
        visited[i] = 1;
        bool notInLoop = true;
        for(int n : graph[i]){
            notInLoop = notInLoop & 
                helper(graph, n, visited);
        }
        if (notInLoop) {
            visited[i] = 2;   
        }
        return notInLoop;
    }
};
