/*
 * 67. Add Binary
 */
 
 class Solution {
public:
    string addBinary(string a, string b) {
        int inc = 0, val = 0, temp = 0;
        string res;
        string *n, *m;
        if (a.size() > b.size()) {n=&a; m=&b;}
        else {n=&b; m=&a;}
        
        int i=n->size()-1, j=m->size()-1;
        while(i>=0) {
            if (j>=0) temp = (*m)[j]-'0';
            else temp = 0;
            val = ((*n)[i] - '0') + temp + inc;
            inc = val / 2;
            val = val % 2;
            res = res + to_string(val);
            //cout <<val << " " <<inc <<" "<<res<<endl;
            --i;
            --j;
        }
        
        if (inc !=0) res = res + to_string(inc);
        reverse (res.begin(), res.end());
        
        return res;
        
    }
};
