/*
 * 1048. Longest String Chain
 */

class Solution {
public:
    static bool cmp(const string& s1, const string& s2) {
            return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        // m[i] is the vector of idx that for each idx j in m[j],
        // words[j] can be a predesessor of word[i]
        //vector<int, vector<int>> m(words.size());      // <<----- Not needed
        
        sort(words.begin(), words.end(), cmp);
        
        // group all words at the same length together
        unordered_map<int, vector<int>> wl;
        for(int i=0; i<words.size(); ++i) {
            wl[words[i].size()].push_back(i);
        }
        
        // dp[i] is the length of longest word chain ends with idx i
        vector<int> dp(words.size(), 1);
        int res = 1;
        for(int i=0; i<words.size(); ++i) {
            // iterate through all words that has length = words[i].size()+1
            if (wl.find(words[i].size()+1) == wl.end()) continue;
            for (int j=0; j<wl[words[i].size()+1].size(); ++j) {
                int t = wl[words[i].size()+1][j];
                string &s1 = words[i];
                string &s2 = words[t];
                //cout<<s1<<" "<<s2<<endl;
                if (p(s1, s2)) {  
                    //cout<<s1<<" "<<s2<<endl;
                    dp[t] = max(dp[t], dp[i]+1);
                    res = max(dp[t], res);
                }
            }
        }
        
        return res;
    }
    
    bool p(const string& s1, const string& s2) {
        int i=0, j=0;
        while(i<s1.size() && j<s2.size()) {
            if (s1[i] == s2[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return i==s1.size() && (j==s2.size() || j==s2.size()-1);
        
    }
};
