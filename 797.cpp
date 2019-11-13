/*
 * 797. All Paths From Source to Target
 */
 
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        
        vector<int> temp = {0};
        helper(res, graph, 0, temp);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<vector<int>>& graph,
                int cur, vector<int>& temp) {
        //cout<<cur<<endl;
        if (cur == graph.size()-1) {
            res.push_back(vector<int>(temp));
            return;
        }
        
        for(int i=0; i<graph[cur].size(); ++i) {
            temp.push_back(graph[cur][i]);
            helper(res, graph, graph[cur][i], temp);
            temp.pop_back();
        }
    }
};
