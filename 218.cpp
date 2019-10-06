/*
 * 218. The Skyline Problem
 *
 */
 
class Solution {
public:
    class P{
    public:
        int idx;
        int h;
        
        P(int i, int hh): h(hh), idx(i) {};
        
        bool operator<(const P& p) const {
            if(this->idx == p.idx)
                return this->h < p.h;
            return this->idx > p.idx;
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // enter and leave list of <idx, and height>
        // multimap for all current buildings, sort from highest to lowest
        multiset<int, greater<int>> m;
        priority_queue<P> enter;
        priority_queue<P> leave;
        vector<vector<int>> res;
        
        for(int i=0; i<buildings.size(); ++i) {
            enter.push(P(buildings[i][0], buildings[i][2]));
            leave.push(P(buildings[i][1], buildings[i][2]));
        }
        
        while(!enter.empty() || !leave.empty()) {
            int e = enter.empty()? INT_MAX: enter.top().idx;
            int l = leave.empty()? INT_MAX: leave.top().idx;
            int i = min(e, l);
            int cur = 0;
            if(!m.empty()) {
                cur = *(m.begin());
            }
            
            if (e<=l && !enter.empty()) {
                // add height to set
                P t = enter.top();
                enter.pop();
                m.insert(t.h);
                while(!enter.empty() && enter.top().idx == t.idx) {
                    m.insert(enter.top().h);
                    enter.pop();
                }
               
                //cout<<"enter "<<t.h<<endl;
            }
            if (l<=e) {
                P t = leave.top();
                leave.pop();
                m.erase(m.lower_bound(t.h));
                while(!leave.empty() && leave.top().idx == t.idx) {
                    m.erase(m.lower_bound(leave.top().h));
                    leave.pop();
                }
                //cout<<"leave "<<t.h<<endl;
            }
            int newh = 0;
            if(!m.empty()) {
                newh = *(m.begin());
                //cout<<newh<<endl;
            }
            
            if(newh != cur) {
                res.push_back(vector<int>{min(l, e), newh});
            }
        }
        
        return res;
    }
};
