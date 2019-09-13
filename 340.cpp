/*
 * 340.Longest Substring with At Most K Distinct Characters
 *
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 *
 */
 class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        /*
         * Sliding window.
         * If it is invalid after right pointer ++,
         *  1. Compute current max and 
         *  2. Move left pointer
         * Remember when r==s.size(), it is still a candidate res.
         *
         */
        if(k==0)
            return 0;
        unordered_map<char, int> m; // Ref count of all element in the window
        int res = -1;
        int l = 0, r = 0;
        while(l<s.size()) {
            if (r>=s.size()) {
                res = max(res, r-l);
                break;
            }
            while (m.size()<=k && r<s.size()) {
                if (m.size()<k || (m.size() ==k && m.find(s[r]) != m.end())) {
                    m[s[r]] ++;
                    r++;
                    continue;
                } else {
                    res = max(r-l, res);
                    while (m.size() == k) {
                        m[s[l]]--;
                        if(m[s[l]]==0) {
                            //cout<<m.size()<<" "<<s[l]<<endl;
                            m.erase(s[l]);
                            ++l;
                            //cout<<m.size()<<endl;
                            break;
                        }
                        ++l;
                    }
                    //cout<<"b "<<l<<" "<<r<<endl;
                    break;
                }
            }
        }
        return res==-1? s.size(): res;
    }
};
