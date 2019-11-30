/*
 * 93. Restore IP Addresses
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 */
 
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur = "";
        
        helper(res, cur, s, 0, 0, 0);
        return res;
    }
    
    void helper(vector<string>& res, string cur, string& S, int idx,
                int section, int val) {
        if (idx == S.size()){
            if (val<=255 && section == 3) {
                string ress = cur + "." + to_string(val);
                if (ress.size() == S.size()+3)
                    res.push_back(ress);
            }
            return;
        }
        if (section >=4 || val>255) {
            return;
        }
        
        // curidx starts next section
        if (idx!=0) {
            string n;
            if (section==0) {
                n = to_string(val);
            } else {
                n = cur + "." + to_string(val);
            }
            //cout<<n<<endl;
            helper(res, n, S, idx+1, section+1, S[idx]-'0');
        }
        
        //curidx in this section
        if ((val*10 + (S[idx]-'0'))<=255) {
            //string nn = cur+S[idx];
            //cout<<nn<<endl;
            helper(res, cur, S, idx+1, section, val*10 + (S[idx]-'0'));
        }        
    }
};
