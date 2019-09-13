/*
 * 269. Alien Dictionary
 *
 * There is a new alien language which uses the latin alphabet. However,
 * the order among letters are unknown to you. You receive a list of non-empty words from
 * the dictionary, where words are sorted lexicographically by the rules of this new language.
 * Derive the order of letters in this language.
 *
 * Exp1:
 *  [ "wrt", "wrf", "er", "ett", "rftt"] -> "wertf"
 */
 
 class Solution {
public:
    /*
     * Topologital sort:
     *  inDegree it a list update every time. Remove inDegree==0.
     *  outDegree is a const vector<list> reference who's inDegree
     *  needs to be --1 when we remove a node.
     *  Depending on the specific question, we remove either InDegree or OutDegree ==0
     *  Then BFS starting with inDegree ==0;
     */
    string alienOrder(vector<string>& w) {
        // construct inDegree and outDegree
        // a<b, then a->b. 
        unordered_map<char, int> inDegree;
        unordered_map<char, set<char>> outDegree;
        for(int i=0; i<w.size()-1; ++i) {
            // compare w[i][j] and w[i+1][j],
            for(int j=0; j<min(w[i].size(), w[i+1].size()); ++j) {
                if(w[i][j] == w[i+1][j])
                    continue;
                // w[i][j] < w[i+1][j]
                //cout<<w[i][j] <<" < "<< w[i+1][j]<<endl;
                // For tha same a<b, they should not be added twice.
                if (outDegree[w[i][j]].find(w[i+1][j]) == outDegree[w[i][j]].end()) {
                    inDegree[w[i+1][j]] ++;
                    outDegree[w[i][j]].insert(w[i+1][j]);
                }
                break;
            }
        }
        /*for(auto i:inDegree) {
            cout<<i.first<<":"<<i.second<<" ";
        } cout<<endl;*/
        // If no < relation for this letter, it will be added as 0 inDegree 
        for(auto s:w) {
            for(auto c:s) {
                if(inDegree.find(c) == inDegree.end()) {
                    inDegree[c] = 0;
                }
            }
        }
        
        queue<char> q;
        string res;
        for(auto it:inDegree) {
            if(it.second == 0) {
                //cout<<it.first<<endl;
                q.push(it.first);
            }
        }
        while (!q.empty()) {
            char t = q.front();
            res+=t;
            q.pop();
            for(auto n:outDegree[t]) {
                inDegree[n]--;
                if(inDegree[n]==0) {
                    q.push(n);
                }
            }
        }
        cout<<res<<endl;
        if (res.size() != inDegree.size()){
            return "";
        } else{
            return res;
        }
    }
};
