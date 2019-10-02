/*
 * 247. Strobogrammatic Number II
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 */
 
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char, char> d1;
        d1['1'] = '1';
        d1['0'] = '0';
        d1['8'] = '8';
        d1['6'] = '9';
        d1['9'] = '6';
        
        
        vector<string> res;
        string temp;
        helper(d1, n, 0, temp, res);
        
        for (string& s:res) {
            for(int i=n/2-1; i>=0; --i) {
                s+=d1[s[i]];
            }
        }
        if (n==1) {
            res.push_back("0");
        }
        return res;
    }
    
    void helper(const unordered_map<char, char>& d1,
                int n, int idx, string& temp, vector<string>& res) {
        if(idx==n/2 && n%2==0) {
            res.push_back(string(temp));
            return;
        }
        if(idx==n/2 && n%2==1) {
            res.push_back(string(temp+'1'));
            res.push_back(string(temp+'8'));
            if(n!=1) {
                res.push_back(temp+'0');
            }
            return;
        }
        for(auto& it:d1) {
            if(idx == 0 && it.first == '0')
                continue;
            temp += it.first;
            helper(d1, n, idx+1, temp, res);
            temp.pop_back();
        }
        
    }
};
