/*
 * 986. Interval List Intersections
 *
 * Find intersection of two intervals list
 */
 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int a=0, b=0;
        while(a<A.size() && b<B.size()) {
            // no intersect
            if(A[a][1] < B[b][0]) {  //A[a].end < B[b].start
                ++a;
                continue;
            }
            if(B[b][1] < A[a][0]) {  //B[b].end < A[a].start
                ++b;
                continue;
            }
            // If there are intersections, who ends first ++
            vector<int> temp{max(A[a][0], B[b][0]), min(A[a][1], B[b][1])};
            res.push_back(temp);
            if(A[a][1]< B[b][1]) {
                ++a;
            } else {
                ++b;
            }
        }
        
        return res;
    }
};
