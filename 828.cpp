/*
 * 828. Unique Letter String
 *
 * A character is unique in string S if it occurs exactly once in it.
 * For example, in string S = "LETTER", the only unique characters are "L" and "R".
 * 
 * Let's define UNIQ(S) as the number of unique characters in string S.
 * For example, UNIQ("LETTER") =  2.
 * 
 * Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.
 * 
 *  If there are two or more equal substrings at different positions in S, we consider them different.
 */
 
class Solution {
public:
    int uniqueLetterString(string S) {
        /*
        * For each letter X, it contributes to 
        * 1. #of letters between (n-1)th X and nth X, 
        * 2. # of letters between (n+1)th X and nth X, 
        * 3. result of 1 * result of 2
        */
        
        unordered_map<char, vector<int>> m;
        for(int i=0; i<S.size(); ++i) {
            m[S[i]].push_back(i);
        }
        
        int res = 0;
        for(auto& it:m) {
            cout<<it.first<<endl;
            for(int i=0; i<it.second.size(); ++i) {
                int prev = -1;
                int next = S.size();
                if(i!=0) {
                    prev = it.second[i-1];
                }
                if(i!=it.second.size()-1) {
                    next = it.second[i+1];
                }
                prev = abs(it.second[i] - prev-1);
                next = abs(next - it.second[i]-1);
                res += prev + next + prev*next +1;
                //cout<<prev<<" "<<next<<endl;
            }
            //cout<<endl;
        }
        return res;
    }
};
