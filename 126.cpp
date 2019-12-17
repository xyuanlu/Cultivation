/*
 * 126. Word Ladder II
 */
 
class Solution {
public:
    class P{
    public:
        int idx;
        int l;
    };
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<int, vector<int>> edges;
        // remenber for each node, what's its last step
        vector<unordered_set<int>> prev(wordList.size());
        int endNode = -1;
        int N = wordList.size()-1;   // idx of begin word
        for(int i=0; i<wordList.size(); ++i) {
            if (wordList[i] == endWord)
                endNode = i;
            for (int j=i+1; j<wordList.size(); ++j) {
                if (distance(wordList, i, j)) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        if (endNode == -1)
            return vector<vector<string>>();
        
        // doing BFS
        queue<P> q;
        // idx and level. only same idx and same level is ok
        unordered_map<int, int> visited; 
        q.push({endNode, 1});
        int minStep = INT_MAX;
        while(!q.empty()) {
            P t = q.front();
            q.pop();
            if (t.l > minStep)
                break;
            if (t.idx == N) {
                minStep = t.l;
            } else {
                for(int i=0; i<edges[t.idx].size(); ++i) {
                    if (visited.find(edges[t.idx][i]) == visited.end() 
                       || visited[edges[t.idx][i]] == t.l+1) {
                        prev[edges[t.idx][i]].insert(t.idx);
                    }
                    if (visited.find(edges[t.idx][i]) == visited.end()) {
                        q.push({edges[t.idx][i], t.l+1});
                        visited[edges[t.idx][i]] = t.l+1;
                         //prev[edges[t.idx][i]].insert(t.idx);
                    }
                }
            }
        }
        
        for(int it:prev[N]) {
            cout<<it<<": "<<wordList[it]<<" ";
        }
        cout<<endl;
        cout<<"num "<<prev[N].size()<<endl;
        
        cout<<N<<" "<<minStep<<endl;
        // DFS to find the res;
        vector<vector<string>> res;
        vector<string> temp = {beginWord};
        unordered_set<int> v;
        v.insert(N);
        helper(res, v, wordList, prev, temp, N, minStep, endNode);
        
        return res;
    }
    
    
    void helper(vector<vector<string>>& res, unordered_set<int>& v,
                vector<string>& wordList, vector<unordered_set<int>>& prev,
                vector<string>& temp, int curNode, int N, int endNode) {
        //cout << "XXX -> " << curNode << endl;
        //if (temp.size()==N) {
            if (curNode == endNode) {
               // cout << "XXX "<<temp.size() << endl;
                vector<string> n = temp;
                //reverse(n.begin(), n.end());
                res.push_back(n);
           // }
            return;
        }
        for(auto it : prev[curNode]) {
            if (v.find(it) != v.end()) {
                continue;
            }
            temp.push_back(wordList[it]);
            v.insert(it);
            helper(res, v, wordList, prev, temp, it, N, endNode);
            v.erase(it);
            temp.pop_back();
        }
    }
    
    
    // return true if wordList[i] and wordList[j] distance == 1
    bool distance(vector<string>& wordList, int i, int j) {
        bool diff = false;
        for(int h=0; h<wordList[i].size(); ++h) {
            if (wordList[i][h] != wordList[j][h]) {
                if (diff)
                    return false;
                diff = true;
            }
        }
        return diff;
    }
};
