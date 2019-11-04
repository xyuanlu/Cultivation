/*
 * 1088. Confusing Number II
 */
 
class Solution {
public:
    vector<int> m = {0, 1, 6, 8, 9};
    unordered_map<int, int> mm{{0,0}, {1, 1}, {8, 8}, {6, 9}, {9, 6}};
    
    int confusingNumberII(int n) {
        int nn = n;
        vector<int> N;
        while(n>0) {
            N.push_back(n%10);
            n=n/10;
        }
        
        reverse(N.begin(), N.end());
        /*for(auto i:N) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        
        vector<int> cur;
        cur.reserve(N.size());
        return helper(N, cur, 0, nn, 0);
    }
    
    int helper(const vector<int>& N, vector<int>& cur, long long x, int n, int d) {
        if (d == N.size()) {
            if (isValid(cur)) {
                //cout<<"1: "<<x<<endl;
                /*for(auto i:cur) {
                    cout<<i<<" ";
                } cout<<endl;*/
                return 1;
            }
            return 0;
        }
        int res = 0;
        for (int i=0; i<m.size(); ++i) {
            //cout<<"2: "<<x<<endl;
            //int d = cur.size();
            if (x*10+m[i]>n) {
                return res;
            }
            cur.push_back(m[i]);
            res += helper(N, cur, x*10+m[i], n, d+1);
            cur.pop_back();
        }
        return res;
    }
    
   /* bool isValid(long long x, int d) {
        int l , r;
        
        unordered_map<int, int> mm{{0,0}, {1, 1}, {8, 8}, {6, 9}, {9, 6}};
        while(x>0) {
            l = x/pow(10,(d-1));
            r = x%10;
            //cout<<l<<" "<<d<<" "<<(10^(d-1))<<" "<<r<<endl;
            if (l != mm[r]){
                return true;
            }
            x=x%(10^(d-1));
            x=x/10;
            d=d-2;
            cout<<l<<" "<<r<<endl;
        }
        return false;
        
    }*/
    
    bool isValid(vector<int>& n) {
        /*for(auto i:n) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        int l=0, r=n.size()-1;
        while(l<n.size() && n[l]==0) {
            ++l;
        }
        
        
        while(l<=r) {
            if (n[l] != mm[n[r]]){
                return true;
            }
            ++l;
            --r;
        }
        return false;
        
    }
};
