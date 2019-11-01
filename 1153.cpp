/*
* 1153. String Transforms Into Another String
* Given two strings str1 and str2 of the same length, determine whether you can
* transform str1 into str2 by doing zero or more conversions.
*
* In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.
*
* Return true if and only if you can transform str1 into str2.
*/

class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char, char> e;
        vector<int> inDegree(26, 0); 
        for (int i=0; i<str1.size(); ++i) {
            if (e.find(str1[i]) == e.end()) {
                e[str1[i]]=str2[i];
                inDegree[str2[i]-'a']++;
            } else if ( e[str1[i]]!=str2[i]){
                return false;
            }
        }
        
        // find if we have loop in the graph
        // 0 unvisited, 1 visiting, 2 visited
        int numCircle = 0;
        vector<int> visited(26, 0);
        for(int i=0; i<26; ++i) {
            if (visited[i]==0 && e.find('a'+i) != e.end()) {
                //cout<<('a'+i)<<endl;
                if (!helper(e, 'a'+i, visited))
                    numCircle++;
            }
        }
        
        // outDegree ==0 or Indegree ==0 can help break circle
        cout<<numCircle<<endl;
        for(int i=0; i<26; ++i) {
            if(numCircle==0)
                break;
            if (e.find('a'+i) == e.end() || inDegree[i]==0)
                numCircle--;
        }
        return numCircle==0;
    }
    
    bool helper(unordered_map<char, char>& e, char cur, vector<int>& visited) {
        if (visited[cur-'a'] ==2) return true;
        if (visited[cur-'a'] ==1) return false;
        visited[cur-'a'] = 1;
        int res = true;
        if (e.find(cur)!= e.end() && e[cur] != cur) {
            res = helper(e, e[cur], visited);
        }
        visited[cur-'a'] = 2;
        return res;
    }
};
