/*
 * 953. Verifying an Alien Dictionary
 */
 
 class Solution {
public:
    // Create Maximum Number uses this question as a part of it
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26);
        for(int i=0; i<order.size(); ++i) {
            dict[order[i]-'a'] = i;
        }
        for(int i=0; i<words.size()-1; ++i) {
            if(!isLess(words[i], words[i+1], dict))
                return false;
        }
        return true;
    }
    
    bool isLess(const string& a, const string& b, const vector<int>& dict) {
        int idx1 = 0, idx2 = 0;
        while(idx1<a.size() && idx2<b.size()) {
            if(dict[a[idx1]-'a'] < dict[b[idx2]-'a']) { 
                return true;
            }
            if(dict[a[idx1]-'a'] > dict[b[idx2]-'a']) {
                return false;
            }
            idx1++;
            idx2++;
        }
        return a.size() < b.size();
    }
};
