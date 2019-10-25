/*
 * 524. Longest Word in Dictionary through Deleting
 *
 * Given a string and a string dictionary, find the longest string in the dictionary that
 * can be formed by deleting some characters of the given string. If there are more than
 * one possible results, return the longest word with the smallest lexicographical order.
 * If there is no possible result, return the empty string.
 */

 
class Solution {
public:
    struct cmp{
        bool operator()(const string& s1, const string& s2) const {
            if(s1.size()==s2.size()) {
                return s1>s2;
            }
            else return s1.size()<s2.size();
        }  
    };
    
    string findLongestWord(string s, vector<string>& d) {
        priority_queue<string, vector<string>, cmp> p;
        
        for(int k=0; k<d.size(); ++k) {
            int i=0, j=0;
            while(i<d[k].size() && j<s.size()) {
                if (d[k][i] == s[j]) {
                    ++i;
                    ++j;
                } else {
                    ++j;
                }
            }
            //cout<<i<<" "<<j<<endl;
            if (i==d[k].size()) {
                //cout<<d[k]<<endl;
                p.push(d[k]);
            }
        }
        
        return p.size()==0? "":p.top();
    }
};
