class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        map<int, set<int>> memo;
        vector<int> temp;
        for (int i=0; i<pre.size(); ++i) {
            memo[pre[i][0]].insert(pre[i][1]);
        }
        for (int i=0; i<N; ++i) {
            if (memo.find(i) == memo.end()) {
                temp.push_back(i);
            }
        }

        while(!temp.empty() ) {
            vector<int> cur_temp;
            for(auto &it:memo) {
                for(auto it2:temp) {
                    if(it.second.find(it2)!=it.second.end()) {
                        it.second.erase(it2);
                        //cout<<it.first<<" "<<"remove"<<it2<<" "<<it.second.size()<<endl;
                    }
                }
                if (it.second.empty()) {
                    cur_temp.push_back(it.first);
                }
            }
            temp = cur_temp;
            for(auto it:cur_temp) {
                //cout<<it<<"removed"<<endl;
                memo.erase(it);
            }
        }
        return memo.empty();
    }
};
