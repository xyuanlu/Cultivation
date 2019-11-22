/*
* 245. Shortest Word Distance III
* Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
*
* word1 and word2 may be the same and they represent two individual words in the list.
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, set<int>> m;
        
        for(int i=0; i<words.size(); ++i) {
            m[words[i]].insert(i);
        }
        
        int res = words.size()+1;
        for(auto &it:m[word1]) {
            int idx = it;
            auto prev = m[word2].lower_bound(idx);
            if (prev != m[word2].begin()) {
                prev --;
                res = min(res, abs(idx - *prev));
            }
            auto next =  m[word2].upper_bound(idx);
            if (next != m[word2].end()) {
                res = min(res, *next-idx);
            }
        }
        return res;
    }
};
