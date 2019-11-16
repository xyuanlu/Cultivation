/*
 * 1024. Video Stitching
 * You are given a series of video clips from a sporting event that lasted T seconds.
 * These video clips can be overlapping with each other and have varied lengths.
 *
 * Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at
 * time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7]
 * can be cut into segments [0, 1] + [1, 3] + [3, 7].
 * 
 * Return the minimum number of clips needed so that we can cut the clips into segments that
 * cover the entire sporting event ([0, T]).  If the task is impossible, return -1.
 */
 
class Solution {
public:
    // sort pair by start, if they have same start, whoever ends
    // later should be the first.
    static bool cmpare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), cmpare);
        int res = 0;
        /*for(auto &it:clips) {
            cout<<it[0]<<" "<<it[1]<<endl;
        }*/
        
        // prev clip ends, and begin
        int prev = 0; //, b = -1;
        for(int i=0; i<clips.size(); ++i) {
            if (clips[i][0]>prev)
                return -1;
            int j=i, end = clips[i][1];
            while(j<clips.size() && clips[j][0]<=prev) {
                if (clips[j][1]>=T) {
                    return ++res;
                }
                end = max(end, clips[j][1]);
                ++j;
            }
            //b = clips[]
            res++;
            i=j-1;
            prev=end;
        }
        return -1;
    }
};
