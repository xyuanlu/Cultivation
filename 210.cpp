class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree(n, 0);
        vector<vector<int>> outDegree(n);
        queue<int> q;

        for(int i=0; i<prerequisites.size(); ++i) {
            inDegree[prerequisites[i][0]]++;
            outDegree[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0; i<n; ++i) {
            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int cur = q.front();
            res.push_back(cur);
            q.pop();
            // Every time when an element is clear, all it's dependent's inDgree --
            for(auto it:outDegree[cur]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(res.size()== n)
            return res;
        else return {};
    }
};
