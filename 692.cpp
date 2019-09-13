/*
 * 692. Top K Frequent Words
 *
 * Given a non-empty list of words, return the k most frequent elements.
 *
 * Your answer should be sorted by frequency from highest to lowest.
 * If two words have the same frequency, then the word with the lower alphabetical order comes first.
 */
 class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, string>& p1, const pair<int, string>& p2){
            if(p1.first != p2.first)
                return p1.first < p2.first;
            else 
                return p1.second > p2.second;
        }  
        
    };
    typedef priority_queue<pair<int, string>,vector<pair<int, string>>, cmp> freqQ;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> freq;
        for(string w : words) {
            freq[w]++;
        }
        freqQ fq;
        
        for(auto it:freq) {
            fq.push(make_pair(it.second, it.first));
        }
        
        
        while(k>=0 && !fq.empty()) {
            //cout<<fq.top().second<<endl;
            res.push_back(fq.top().second);
            fq.pop();
            k--;
            if(k==0)
                break;
        }
        return res;
    }
};
