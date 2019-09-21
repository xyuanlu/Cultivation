/*
* 246. Strobogrammatic Number
*
* A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        for(int i=0; i<=num.size()-1-i; ++i) {
            if(m.find(num[i]) == m.end())
                return false;
            //cout<<i<<endl;
            if(i==num.size()-1-i) {
                return num[i]=='0' || num[i]=='8' || num[i]=='1';
            }
            if (m[num[i]] != num[num.size()-1-i]) {
                return false;
            }          
        }
        return true;
     }
};
