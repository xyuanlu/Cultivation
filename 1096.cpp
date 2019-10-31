/*
 * 1096. Brace Expansion II
 */
 
 /*
 *      exp  -> {com}exp
 *              | alphaexp
 *              | epslon   return [""]
 *             
 *      com -> exp Rcom
 *      Rcom -> , com
 *           | epslon
 */

class Solution {
public:
    int idx = 0;
    string S;
    
    set<string> exp() {
        if(idx == S.size()) {
            return set<string>{""};
        }
        //cout<<idx<<endl;
        if (S[idx]=='{') {
            ++idx;
            set<string> v1 = com();
            assert(S[idx]=='}');
            ++idx;
            set<string> v2 = exp();
            // v1 X V2
            set<string> res;
            for(auto& s1:v1) {
                for(auto &s2 :v2) {
                    res.insert(s1+s2);
                    //cout<<s1+s2<<endl;
                }
            }
            return res;
        } else if (isalpha(S[idx])) {
            string s(1, S[idx]);
            idx++;
            set<string> v1 = exp();
            set<string> res;
            for(auto& s2:v1) {
                res.insert(s+s2);
            }
            return res;
        }
        else {
            return set<string>{""};
        }
    }
    
    set<string> com() {
        //cout<<"c "<<idx<<endl;
        set<string> v1 = exp();
        set<string> v2 = rcom();
        for(auto &s2:v2) {
            v1.insert(s2);
        }
        return v1;
    }
    
    set<string> rcom(){
        //cout<<"rc "<<idx<<endl;
        if (S[idx]==','){
            ++idx;
            return com();
        } else {
            return set<string>();
        }
    }
    
    vector<string> braceExpansionII(string expression) {
        S = expression;
        set<string> m = exp();
        vector<string> res;
        for(auto &it:m) {
            res.push_back(it);
        }
        return res;
    }
};
