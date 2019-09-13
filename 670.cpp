/*
 * 670. Maximum Swap
 *
 *  Given a non-negative integer, you could swap two digits at most once to get the
 *  maximum valued number. Return the maximum valued number you could get.
 */
 
 class Solution {
public:
    int maximumSwap(int num) {
        /*
         * Compare each digit in num to the maximum mossible number
         * The first mismatch digit is the target value at this position.
         * Find target alur from end.
         */
        string s = std::to_string(num);
        string ss = s;
        sort(ss.begin(), ss.end(), std::greater<char>());
        cout<<ss<<endl;
        char targetval;
        int idx = -1;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] != ss[i]) {
                targetval = ss[i];
                idx = i;
                break;
            }
        }
        //cout<<idx<<" "<<targetval;
        
        // find targetVal from end. 
        // it is better to move a larger fidgit closer from end
        if(idx == -1)
            return num;
        int i=s.size()-1;
        for(; i>=0; --i) {
            if(s[i] == targetval) {
                break;
            }
        }
        // swap i and idx
        char t = s[idx];
        s[idx] = s[i];
        s[i] = t;
        return stoi(s);
    }
};
