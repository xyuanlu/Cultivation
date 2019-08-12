class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> memo;
        for(const auto &it:tickets) {
            memo[it[0]].insert(it[1]);
        }

        vector<string> res {"JFK"};
        string temp = "JFK";
        dfs(memo, temp, res, tickets.size());
        return res;
    }

    bool dfs(unordered_map<string, multiset<string>> &memo, string &cur, vector<string> &res, int N) {
        if(res.size() == N+1) {
            return true;
        }
        for(auto it : memo[cur]) {
            unordered_map<string, multiset<string>> memo2(memo);
            memo2[cur].erase(memo2[cur].lower_bound(it));
            res.push_back(it);
            //cout<<it<<endl;
            if (dfs(memo2, it, res, N))
                return true;
            res.pop_back();
        }
        return false;
    }
};
