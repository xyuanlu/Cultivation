/*
* 1055. Shortest Way to Form String
*   Input: source = "xyz", target = "xzyxz"
*   Output: 3
*/

class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, set<int>> m;
        for(int i=0; i<source.size(); ++i) {
            m[source[i]].insert(i);
        }
        int res=1;
        int prev = -1;
        for(int i=0; i<target.size(); ) {
            //cout<<prev<<endl;
            auto it = m.find(target[i]);
            if (it == m.end()) {
                return -1;
            }
            auto it2 = it->second.upper_bound(prev);
            if (it2==it->second.end()) {
                res++;
                prev = -1;
            } else {
                prev = *it2;
                ++i;
            }
        }
        return res;
    }
};
