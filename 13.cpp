class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        
        int res = 0;
        for(int i=0; i<s.size(); ++i) {
            if(i!=s.size()-1 && dict[s[i]]<dict[s[i+1]])
                res -=dict[s[i]];
            else
                res += dict[s[i]];
        }
        return res;
    }
};
