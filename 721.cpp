/*
 * 721. Accounts Merge
 */
 
class UnionFind{
public:
    int size = 0;
    vector<int> m;
    vector<int> d;
    
    UnionFind(int n) {
        for(int i=0; i<n; ++i) {
            m.push_back(i);
            d.push_back(1);
        }
        size = n;
    }
    
    int GetParent(int a) {
        int t = m[a];
        if(t != a) {
            t = GetParent(t);
        }
        m[a] = t;
        return t;
    }
    
    int isUnited(int a, int b) {
        return GetParent(a) == GetParent(b);
    }
    
    void Union(int a, int b) {
        int aa = GetParent(a), bb = GetParent(b);
        if (aa == bb)
            return;
        if(d[aa] < d[bb]) {
            m[aa] = bb;
            d[bb] ++;
        } else {
            m[bb] = aa;
            d[aa] ++;
        }
        size--;
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(accounts.size());
        map<string, int> m; //stores the group number of each email.
        map<int, string> acc; // stores the account number map to group name.
        for(int i=0; i<accounts.size(); ++i) {
            string name = accounts[i][0];
            int group = i;
            acc[i] = name;
            for(int j=1; j<accounts[i].size(); ++j) {
                if(m.find(accounts[i][j]) != m.end()) {
                    group = m[accounts[i][j]];
                    uf.Union(group, i);
                } else {
                    m[accounts[i][j]] = group;
                }
            }
        }
        
        map<int, vector<string>> m2;
        vector<vector<string>> res;
        for(auto& it:m) {
            int group = it.second;
            m2[uf.GetParent(group)].push_back(it.first);
        }
        for(auto& it:m2) {
            vector<string> temp = it.second;
            temp.insert(temp.begin(), acc[it.first]);
            //temp.push_back(it.second);
            res.push_back(temp);
        }
        return res;
    }
};
