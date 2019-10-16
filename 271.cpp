/*
 * 271. Encode and Decode Strings
 * Design an algorithm to encode a list of strings to a string. The
 * encoded string is then sent over the network and is decoded back to the original list of strings.
 */
 
class Codec {
public:
    // "*3abc*4abcd*5abcde"..... 
    //  * + len + str1...
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(int i=0; i<strs.size(); ++i) {
            int len = strs[i].size();
            res += "*"+to_string(len);
            res += "*"+strs[i];
        }
        cout<<res<<endl;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int len = 0;
        string t;
        for(int i=0; i<s.size(); ++i) {
            if (s[i]=='*') {
                len = 0;
                ++i;
            }
            while(isdigit(s[i])){
                len = len*10+(s[i]-'0');
                ++i;
            }
            assert(s[i]=='*');
            ++i;
            //cout<<i<<" "<<len<<endl;
            res.push_back(s.substr(i, len));
            i = i+len-1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
