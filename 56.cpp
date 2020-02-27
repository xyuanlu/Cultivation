/*
 * 56. Merge Intervals
 */
 
class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
            if (v1[0] == v2[0])
                return v1[1]< v2[1];
            else 
                return v1[0]<v2[0];
        }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), compare);
        
        for(int i=0; i<intervals.size(); ) {
            int begin = intervals[i][0], end = intervals[i][1];
            int j = i+1;
            for(; j<intervals.size(); ++j) {
                if (intervals[j][0] > end)
                    break;
                else 
                    end = max(end, intervals[j][1]);
            }
            res.push_back({begin, end});
            i = j;
        }
        
        return res;
    }
};
