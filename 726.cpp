/*
 * 726. Number of Atoms
 *
 * formula = "K4(ON(SO3)2)2"
 * Output: "K4N2O14S4"
 */
 
 class Solution {
public:
    string countOfAtoms(string formula) {
        int i=0;
        map<string, int> m;
        string res;
        for(auto kv:helper(formula, i)) {
            res+=kv.first;
            //cout<<kv.second<<endl;
            if(kv.second>1) {
                res+= to_string(kv.second);
            }
        }
        return res;
    }
    
    map<string, int> helper(string &formular, int& i) {
        map<string, int> res;
        while (i<formular.size()) {
            //cout<<i<<endl;
            if (formular[i] == '(') {
                //cout<<"a"<<endl;
                map<string, int> t = helper(formular, ++i);
                int c = getCount(formular, i);
                for(auto kv:t) {
                    res[kv.first] += kv.second * c;
                }
            } else if(formular[i] == ')') {
                //cout<<"b"<<endl;
                ++i;
                return res;
            } else {
                //cout<<"c"<<endl;
                string name = getName(formular, i);
                int c = getCount(formular, i);
                //cout<<c<<endl;
                res[name] += c;
            }
        }
        return res;
    }
    
    int getCount(string &formular, int& idx) {
        int j=0;
        while(idx+j < formular.size() && isdigit(formular[idx+j])) {
            ++j;
        }
        if(j==0)
            return 1;
        int res =  stoi(formular.substr(idx, j));
        idx += j;
        //cout<<res<<endl;
        return res;
    }
    
    string getName(string &formular, int& idx) {
        string res;
        while(idx<formular.size() && isalpha(formular[idx]) &&
              (islower(formular[idx]) || res.empty())) {
            //cout<<"d"<<endl;
            res += formular[idx++];
        }
        return res;
    }
};



