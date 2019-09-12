/*
 * 621. Task Scheduler
 *
 * Given a char array representing tasks CPU need to do. It contains capital letters A to
 * Z where different letters represent different tasks. Tasks could be done without original order.
 * Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 *
 */

class Solution {
public:
    class taskCount{
    public:
        char t;
        int count;
        
        bool operator< (const taskCount& other) const {
            return count < other.count;
        }
    };
    // We can not pre allocate all the same task at once.
    // For A~E 3 times, and F 2 times, we should do abcdeabcdefancdef not abcedabcedabccedf***f
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(char c:tasks) {
            m[c]++;
        }
        priority_queue<taskCount> q, qq;
        for(auto& it:m) {
            taskCount t{it.first, it.second};
            q.push(t);
        }
        
        vector<char> memo;
        for(int i=0; i<=n; ++i) {
            if (!q.empty()) {
                taskCount t = q.top();
                q.pop();
                memo.push_back(t.t);
                t.count--;
                if(t.count>0) {
                    qq.push(t);
                }
            } else {
                memo.push_back('*');
            }
            if(i==n) {
                while(!qq.empty()) {
                    q.push(qq.top());
                    qq.pop();
                }
                if(!q.empty()) {
                    i=-1;
                }
            }
        }
        //for(auto i:memo) {cout<<i<<" ";}
        int i=memo.size()-1;
        for(; i>=0; --i) {
            if(memo[i]!='*')
                break;
        }
        return i+1;
    }
};
