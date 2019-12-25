/*
 * 737. Sentence Similarity II
 */
 
class Solution {
public:
    /*
     * Time complexity for this is O(N*P) -> for each word we need to go through
     * all the pairs in the worest case.
     * If we use UF, TimeComplexity if O(NlogP + P) if we use ranked union
     */
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size() != words2.size())
            return false;
        // a dictionary of similarity
        unordered_map<string, vector<string>> sim;
        for(int i=0; i<pairs.size(); ++i) {
            sim[pairs[i][0]].push_back(pairs[i][1]);
            sim[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0; i<words1.size(); ++i) {
            if (words1[i] == words2[i])
                continue;
            unordered_set<string> v = {words1[i]};
            if (!helper(words1[i], words2[i], sim, v))
                return false;
        }
        
        return true;
    }
    
    bool helper(string& cur, string& w2, unordered_map<string, vector<string>>& sim,
                unordered_set<string>& v) {
        //cout<<cur<<" "<<w2<<endl;
        if (cur == w2) {
            return true;
        }
        
        for (int i=0; i<sim[cur].size(); ++i) {
            if (v.find(sim[cur][i]) != v.end())
                continue;
            v.insert(sim[cur][i]);
            if (helper(sim[cur][i], w2, sim, v))
                return true;
            v.erase(sim[cur][i]);
        }
        return false;
        
    }
};
