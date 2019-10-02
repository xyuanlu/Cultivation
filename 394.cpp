/*
 * 394. Decode String
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside
 * the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 *
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */
 
 class Solution {
public:
    string decodeString(string S) {
        stack<string> s;
        stack<int> c;
        string res;
        string temp;
        int n = 0;
        
        for(int i=0; i<S.size(); ++i) {
            //cout<<S[i]<<endl;
            if (isdigit(S[i])) {
                n = n*10 + S[i]-'0';
                continue;
            }
            if (S[i] == '[') {
                s.push(temp);
                c.push(n);
                n=0;
                temp = "";
                continue;
            }
            if (isalpha(S[i])) {
                temp += S[i];
            }
            if(S[i] == ']') {
                int num = c.top();
                //cout<<num<<endl;
                c.pop();
                while (num>0) {
                    s.top()+=temp;
                    num--;
                }
                temp = s.top();
                s.pop();
            }
            
        }
        
        return temp;
    }
};
