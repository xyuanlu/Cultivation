/*
 * 399. Evaluate Division
 * Equations are given in the format A / B = k, where A and B are variables represented as strings,
 * and k is a real number (floating point number). Given some queries, return the answers. If the answer
 * does not exist, return -1.0.
 */
 
 
 class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> memo;
        for(int i=0; i<equations.size(); ++i) {
            memo[equations[i][0]][equations[i][1]] = values[i];
            memo[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        vector<double> g_res;
        for(const auto &it:queries) {
            double res = 1.0; unordered_set<string> visited;
            visited.insert(it[0]);
            if (helper(memo, it[0], it[1], res, visited)) {
                g_res.push_back(res);
            } else {
                g_res.push_back(-1.0);
            }
        }
        return g_res;
    }
    
    bool helper(unordered_map<string, unordered_map<string, double>> &memo, const string & key,
               const string &target, double &res, unordered_set<string> &visited) {
        if (memo.find(key) == memo.end()) return false;
        if (key == target) {
            return true;
        }
        for (auto it:memo[key]) {
            if (visited.find(it.first) != visited.end())
                continue;
            res = res * it.second;
            visited.insert(it.first);
            if (helper(memo, it.first, target, res, visited))
                return true;
            res = res / it.second;
            visited.erase(it.first);
        }
        return false;   
    }
};
