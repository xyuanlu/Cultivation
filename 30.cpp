/*
 * 30. Substring with Concatenation of All Words
 * 
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words
 * exactly once and without any intervening characters.
 */
 
 class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
         * The starting point of res can only be K*word_len+x where x<word_len
         * We iterate through all word_len, and search starting point=i=k*n
         * to see if every truncate is in the ref count dictionary.
         */
        vector<int> res;
        if(words.size()==0 || words[0].size()==0 || s.size()<words[0].size())
            return res;
        
        // Ref count
        unordered_map<string, int> dict;
        for(auto& s:words) {
            dict[s] ++;
        }
        
        
        int start = 0, len = words[0].size(), found = 0;
        for (int i=0; i<len; ++i) {
            start = i;
            found = 0;
            unordered_map<string, int> m; //Ref count for the current sub string
            for (int j=i; j<s.size(); ) {
                string t = s.substr(j, len);
                // current truncate is not a word
                if (dict.find(t) == dict.end()) {
                    m.clear();
                    found = 0;
                    j=j+len;
                    start = j;
                    continue;
                }
                //cout<<t<<endl;
                // We already have enough words. Use current j as start;
                if(m[t] == dict[t]) {
                    //cout<<"already"<<endl;
                    m.clear();
                    //m[s.substr(start, len)] ++;
                    start = start+len;
                    found = 0;
                    j=start;
                    continue;
                }
                
                if(m[t] < dict[t]) {
                    m[t]++;
                    found++;
                    j = j+len;
                }
               
                // we found an answer, start right shift a truncate
                if(found==words.size()) {
                    res.push_back(start);
                    m[s.substr(start, len)] --;
                    found--;
                    start = start+len;
                }
                
            }
        }
        return res;
    }
};
