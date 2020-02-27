/*
 * 253. Meeting Rooms II
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * find the minimum number of conference rooms required.
 */
 
class Solution {
public:
    typedef priority_queue<int, vector<int>, greater<int>> Rp;
    int minMeetingRooms(vector<vector<int>>& intervals) {
        Rp starts;
        Rp ends;
        
        for(vector<int> in:intervals) {
            starts.push(in[0]);
            ends.push(in[1]);
        }
        
        int curRoom = 0, res = 0;
        while(!starts.empty()) {
            if(starts.top() < ends.top()) {
                // there is a meetings start before any current ongoing end
                curRoom++;
                res = max(res, curRoom); 
                starts.pop();
            } else {
                curRoom--;
                ends.pop();
            }   
        }
        
        return res;
    }
};
