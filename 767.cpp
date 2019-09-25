/*
 * 767. Reorganize String
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 *
 * If possible, output any possible result.  If not possible, return the empty string.
 */
 
 class Solution {
public:
    class P{
    public:
        char c;
        int n;
        
        P(char cc, int nn): c(cc), n(nn) {};
        
        bool operator<(const P p) const{
            return this->n<p.n;
        }
    };
    string reorganizeString(string S) {
        // build a count map for each char. Put in priority queue.
        // each time get the top elememt.
        // If it is the same as res.back, use the second pargest.
        unordered_map<char, int> m;
        for(char c:S) {
            m[c]++;
        }
        priority_queue<P> pq;
        for(auto it:m) {
            pq.push(P(it.first, it.second));
        }
        
        string res;
        while(!pq.empty()) {
            P temp=pq.top();
            pq.pop();
            if(res.size()!=0 && res.back() == temp.c) {
                if(pq.empty()) {
                    return "";
                }
                P tt = pq.top();
                pq.pop();
                pq.push(temp);
                temp = tt;
            }
            res += temp.c;
            temp.n--;
            if(temp.n!=0) {
                pq.push(temp);
            }
        }
        return res;
    }
};
