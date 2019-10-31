/*
 * 809. Expressive Words
 */
 
class Solution {
public:
    class P{
    public:
        char c;
        int count;
    };
    
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        int idx = 0;
        vector<P> m;
        for(int i=0; i<S.size(); ++i) {
            int l=0;
            while(i+l<S.size() && S[i+l] == S[i]) {
                ++l;
            }
            m.push_back({S[i], l});
            i = i+l-1;
        }
        
        
        for(int i=0; i<words.size(); ++i) {
            idx=0;
            bool found = false;
            for (int j=0; j<words[i].size(); ++j) {
                if (words[i][j] != m[idx].c) {
                    cout<<i<<" "<<j<<endl;
                    break;
                }
                int l=0;
                while(j+l<words[i].size() && words[i][j+l] == words[i][j]) {
                    ++l;
                }
                int p = m[idx].count;
                if ((p>=max(3, l)) || p==l) {
                    j+=l;
                    idx++;
                    if(j==words[i].size())
                        found = true;
                    --j;
                } else {
                    //cout<<"a "<<i<<" "<<j<<" "<<found<<endl;
                    break;
                }
            }
            //cout<<found<<endl;
            if(found && idx == m.size())
                res++;
        }
        
        return res;
    }
};
