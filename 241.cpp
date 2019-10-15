/*
 * 241. Different Ways to Add Parentheses
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 */
 
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return helper(input, 0, input.size());
    }
    
    vector<int> helper(const string& s, int l, int r) {
        vector<int> res;
        if (l>=r)
            return res;
        //int num=0;
        
        //cout<<l<<"->"<<r<<endl;
        // find the idx for operator
        vector<int> idx;
        for (int i=l; i<r; ++i) {
            if (s[i]=='+' || s[i]=='-' || s[i]=='*') {
                idx.push_back(i);
            }
        }
        
        for(int i=0; i<idx.size(); ++i) {
            vector<int> left = helper(s, l, idx[i]);
            vector<int> right = helper(s, idx[i]+1, r);
            //cout<<idx[i]<<": "<<endl;
            /*for(int i:left) cout<<i<<" "; cout<<endl;
            for(int i:right) cout<<i<<" "; cout<<endl;
            cout<<endl;*/
            // add combinations to res
            for (int m=0; m<left.size(); ++m) {
                for (int n=0; n<right.size(); ++n) {
                    if (s[idx[i]] == '+') {
                        res.push_back(left[m] + right[n]);
                    }
                    if (s[idx[i]] == '-') {
                        res.push_back(left[m] - right[n]);
                    }
                    if (s[idx[i]] == '*') {
                        res.push_back(left[m] * right[n]);
                    }
                }
            }
        }
        
        if(res.size()==0) {
            //cout<<"x"<<endl;
            res.push_back(stoi(s.substr(l,r-l)));
        }
        return res;
    }
};
