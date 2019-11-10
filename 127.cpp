/*
 * 127. Word Ladder
 */
 
class Solution {
public:
    class P{
    public:
        int n;
        int s;
    };
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // find the edges table
        wordList.push_back(beginWord);
        unordered_map<int, vector<int>> edges;
        int target = -1;
        for(int i=0; i<wordList.size()-1; ++i) {
            if(wordList[i] == endWord) target = i;
            for(int j=i+1; j<wordList.size(); ++j) {
                if (dis(wordList, i, j)) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        
        // BFS
        queue<P> q;
        unordered_set<int> visited;
        visited.insert(wordList.size()-1);
        q.push({(int)wordList.size()-1, 1});  // begin word is the last one
        while(!q.empty()) {
            P cur = q.front();
            q.pop();
            if (cur.n == target)
                return cur.s;
            for (int i=0; i<edges[cur.n].size(); ++i) {
                if (visited.find(edges[cur.n][i])!=visited.end()) continue;
                q.push({edges[cur.n][i], cur.s+1});
                visited.insert(edges[cur.n][i]);
            }
        }
        return 0;
    }
    
    bool dis(const vector<string>& wordList, int a, int b) {
        const string& s1 = wordList[a];
        const string& s2 = wordList[b];
        bool diff = false;
        for(int i=0; i<s1.size(); ++i) {
            if (s1[i]!=s2[i] ) {
                if (diff) return false;
                else diff = true;
            }
        }
        return true;
    }
};
