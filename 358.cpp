/*
 * 358. Rearrange String k Distance Apart
 * Given a non-empty string s and an integer k, rearrange the string such that the same
 * characters are at least distance k from each other.
 * All input strings are given in lowercase letters. If it is not possible to rearrange
 * the string, return an empty string "".
 */
 
class Solution {
public:
    class P{
    public: 
        int c;
        int n;
        
        P(int cc, int nn) : c(cc), n(nn) {};
        
        bool operator<(const P& pp) const {
            return n<pp.n;
        }
    };
    
    string rearrangeString(string s, int k) {
        // Samilar question as the CPU schudular
        // add the latter with largest occurance.
        
        // build ref map and priority queue, it should return the char with
        // most frequent word
        vector<int> rm(26, 0);
        priority_queue<P> m;
        for(char &c:s) {
            rm[c-'a'] ++;
        }
        for(int i=0; i<26; ++i) {
            if(rm[i]!=0) {
                m.push(P(i, rm[i]));
            }
        }
        
        string res;
        queue<P> q;   // q is a copy of prious k chars. we push 0 but do not add back
        while(res.size()<s.size()) {
            //cout<<res<<endl;
            if (res.size() >= k && res.size()>0) {
                P p = q.front();
                q.pop();
                if(p.n!=0)
                    m.push(p);
            }
            if (!m.empty()) {
                P p = m.top();
                m.pop();
                res += ('a'+ p.c);
                p.n --;
                if(p.n>=0) {
                    q.push(p);
                    //cout<<'a'+p.c<<" "<<p.n<<endl;
                }
            } else {
                return "";
            }
        }
        
        return res;
    }
};

