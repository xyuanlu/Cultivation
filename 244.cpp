/*
 * 244. Shortest Word Distance II
 * Design a class which receives a list of words in the constructor, and implements
 * a method that takes two words word1 and word2 and return the shortest distance
 * between these two words in the list. Your method will be called repeatedly many times with different parameters. 
 */

class WordDistance {
public:
    unordered_map<string, set<int>> m;
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); ++i) {
            m[words[i]].insert(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int idx:m[word1]) {
            auto it = m[word2].upper_bound(idx);
            if (it!= m[word2].end())
                res = min(res, *(it)-idx);
        }
        
        for (int idx:m[word2]) {
            auto it = m[word1].upper_bound(idx);
            if (it!= m[word1].end())
                res = min(res, *(it)-idx);
        }
        
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
