/*
 * 753. Cracking the Safe
 * There is a box protected by a password. The password is a sequence of n
 * digits where each digit can be one of the first k digits 0, 1, ..., k-1.
 *
 * While entering a password, the last n digits entered will automatically be matched against the correct password.
 *
 * For example, assuming the correct password is "345", if you type "012345", the box will open
 * because the correct password matches the suffix of the entered password.
 *
 * Return any password of minimum length that is guaranteed to open the box at some point of entering it.
 */
 
class Solution {
public:
    string crackSafe(int n, int k) {
        /*
         * Each password has length k^n, There will be n passwords.
         * So the max will be n*k^n
         * In the optimal solution, each password shares previous (n-1) chars
         * in the optimal string. So we only add 1 chars. 
         * Thus, the optimal solution's length:
         *   k^n  + (n -1)
         * len(first key) + number of chars to be added (the number of remain keys)
         */
        
        unordered_set<string> visited;
        int targetLen = pow(k, n) +n -1;
        string res, cur;
        for(int i=0; i<n; ++i) {
            cur += '0';
        }
        visited.insert(cur);
        helper(cur, res, n, k, targetLen, visited);
        return res;
    }
    
    bool helper(string& cur, string& res, int n, int k, int targetLen,
                unordered_set<string>& visited) {
        if (cur.size()==targetLen) {
            res = cur;
            return true;
        }
        string t = cur.substr(cur.size()-(n-1), n-1);
        for(int i=0; i<k; ++i) {
            char c = '0'+i;
            t += c;
            if (visited.find(t) == visited.end()) {
                cur += c;
                visited.insert(t);
                if (helper(cur, res, n, k, targetLen, visited))
                    return true;
                visited.erase(t);
                cur.pop_back();
            }
            t.pop_back();
        }
        return false;
    }
};
