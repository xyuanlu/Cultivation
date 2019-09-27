/*
 * 140. Word Break II
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 */

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // DP + DFS

        // build the dict
        unordered_set<string> dict;
        for(string s:wordDict) {
            dict.insert(s);
        }

        //DP
        // m[i] has a list of previous point, where for each element p in the list
        // s.substr from index i->p [) forms a word, and from 0 to i has valid break.
        vector<vector<int>> m(s.size()+1);
        vector<bool> memo(s.size()+1, false);
        memo[0] = true;
        for (int i=0; i<s.size(); ++i) {
            for(int l=0; i+l<=s.size(); ++l) {
                string temp = s.substr(i, l);
                if(dict.find(temp)!=dict.end() && memo[i]) {
                    m[i+l].push_back(i);
                    memo[i+l] = true;
                }
            }
        }

        /*for(int i=0; i<=s.size(); ++i) {
            for(auto n:m[i]) {
                cout<<n<<" ";
            }
            cout<<endl;
        }*/

        // DFS
        string temp;
        vector<string> res;
        if(memo[s.size()] == false)
            return res;

        helper(s, res, temp, m, s.size());
        return res;
    }

    void helper(const string& s, vector<string>& res,
                string& temp, vector<vector<int>>& m, int idx) {
        if(idx == 0) {
            reverse(temp.begin(), temp.end());          //<---------- 
            temp.pop_back();
            //cout<<temp<<endl;
            res.push_back(temp);
            return;
        }
        for(int i=0; i<m[idx].size(); ++i) {
            int prevEnd = m[idx][i];
            string ss = s.substr(prevEnd, idx-prevEnd);
            reverse(ss.begin(), ss.end());           //<----------
            //cout<<ss<<endl;
            string t = temp + " " +ss;
            //cout<<temp<<endl;
            helper(s, res, t, m, prevEnd);
        }
    }

};
