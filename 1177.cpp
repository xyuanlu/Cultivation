/*
 * 1177. Can Make Palindrome from Substring
 * 
 * Given a string s, we make queries on substrings of s.
 *
 * For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right],
 * and then choose up to k of them to replace with any lowercase English letter. 
 *
 * If the substring is possible to be a palindrome string after the operations above, the result of the
 * query is true. Otherwise, the result is false.
 *
 * Return an array answer[], where answer[i] is the result of the i-th query queries[i].
 *
 * Note that: Each letter is counted individually for replacement so if for example s[left..right] = "aaa",
 * and k = 2, we can only replace two of the letters.  (Also, note that the initial string s is never modified by any query.)
 */
 
 class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int M = s.size();
        // prefix count
        vector<vector<int>> m;
        vector<int> t(26, 0);
        //t[s[0]-'a'] = 1;
        m.push_back(t);
        for(int i=0; i<s.size(); ++i) {
            m.push_back(m.back());
            //vector<int> tt = m.back();
            m.back()[s[i]-'a']++;
        }
        
        vector<bool> res(queries.size(), 0);
        for(int i=0; i<queries.size(); ++i) {
            int temp = 0;
            int l = queries[i][0];
            int r = queries[i][1];
            for(int j=0; j<26; ++j) {
                if((m[r+1][j] - m[l+1-1][j])%2!=0) {
                    temp++;
                }
            }
            //temp--;
            temp = temp/2;
            //cout<<temp<<endl;
            res[i]=(temp<=queries[i][2]);
        }
        
        return res;
    }
};
