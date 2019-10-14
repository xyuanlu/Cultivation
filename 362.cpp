/*
 * 362. Design Hit Counter
 * Design a hit counter which counts the number of hits received in the past 5 minutes.
 *
 * Each function accepts a timestamp parameter (in seconds granularity) and you may assume that
 * calls are being made to the system in chronological order (ie, the timestamp is monotonically
 * increasing). You may assume that the earliest timestamp starts at 1.
 *
 * It is possible that several hits arrive roughly at the same time.
 */
 
class HitCounter {
public:
    class Pair{
    public:
        int time;
        int count;
        
        Pair(int t, int c):time(t), count(c) {};
        
    };
    queue<Pair> q;
    int num;
    /** Initialize your data structure here. */
    HitCounter() {
        num=0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (!q.empty() && q.back().time == timestamp) {
            q.back().count++;
            num++;
        } else {
            q.push(Pair(timestamp, 1));
            num++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && q.front().time <= timestamp-300 ) {
            num -= q.front().count;
            q.pop();
        }
        return num;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
