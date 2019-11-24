/*
 * 850. Rectangle Area II
 */
 
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        if (rectangles.size()==0)
            return 0;
        
        long long res = 0;
        unsigned long long M = 1e9 + 7;
        // x -> rec number enter/leave at x
        unordered_map<int, vector<int>> ent, ext;
        set<int> xs;
        for(int i=0; i<rectangles.size(); ++i) {
            ent[rectangles[i][0]].push_back(i);
            ext[rectangles[i][2]].push_back(i); 
            xs.insert(rectangles[i][0]);
            xs.insert(rectangles[i][2]);
            
        }
        
        // track the current rectangles
        unordered_set<int> cur;
        int prev = 0;
        for(auto it = xs.begin(); it!=xs.end(); ++it) {
            int i = *it;
            if (ext.find(i) != ext.end()) {
                for(int it:ext[i]) {
                    cur.erase(it);
                }
            }
            if (ent.find(i) != ent.end()) {
                for(int it:ent[i]) {
                    cur.insert(it);
                }
            }
            
            // sort the rectangle index by the rectangle's y1 and y2
            vector<int> srecs(cur.begin(), cur.end());
            sort(srecs.begin(), srecs.end(), [&rectangles](int a, int b) {
                if (rectangles[a][1] == rectangles[b][1]) {
                    return rectangles[a][3] < rectangles[b][3];
                }
                else return rectangles[a][1] < rectangles[b][1];
            });
            
            // merge these sorted intervals
            vector<pair<int, int>> mergedInts;
            for (int idx:srecs) {
                if (!mergedInts.empty() && mergedInts.back().second>=rectangles[idx][1]) {
                    mergedInts.back().second = max(mergedInts.back().second, rectangles[idx][3]);
                } else {
                    mergedInts.push_back(make_pair(rectangles[idx][1], rectangles[idx][3]));
                }
            }
            
            // count
            long long h=0;
            long long w = 0;
            auto it2 = std::next(it);
            if (it2==xs.end())
            {
                continue;
            } else {
                w = *it2 - i;
            }
            for(int j=0; j<mergedInts.size(); ++j) {
                h += mergedInts[j].second - mergedInts[j].first;
            }
            
            //cout<<i<<" "<<h<<" "<<prev<<endl;
            res = (res + h*w % M) %M;
            prev = i;
        }
        return res;
        
    }

};
