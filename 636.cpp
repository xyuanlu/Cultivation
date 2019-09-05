/*
 * On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.
 * We store logs in timestamp order that describe when a function is entered or exited.
 * Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}". 
 * For example, "0:start:3" means the function with id 0 started at the beginning of timestamp 3. 
 * "1:end:2" means the function with id 1 ended at the end of timestamp 2.
 *
 * A function's exclusive time is the number of units of time spent in this function.  Note
 * that this does not include any recursive calls to child functions.
 *
 * The CPU is single threaded which means that only one function is being executed at a given time unit.
 *
 * Return the exclusive time of each function, sorted by their function id.
 *
 * Example 1:
 * Input:
 *  n = 2
 *  logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
 *  Output: [3, 4]
 *
 */
 
 class Solution {
public:
    class event{
    public:
        int time;
        int func;
        bool start;  // true means funstion start, false means function ends
        
        event(int t, int f, bool s): time(t), func(f), start(s) {};
        
        bool operator<(const event& e) {
            return this->time < e.time;
        }
        
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<event> events;      // The events are sorted by time
        vector<int> time(n, 0);    // Time spent for each function
        stack<int> c;              // stack of functions that CPU executes
        
        // parse
        for(int i=0; i<logs.size(); ++i) {
            auto found = logs[i].find(":");
            int f = stoi(logs[i].substr(0, found));
            auto found2 = logs[i].find(":", found+1);
            bool s = (found2 - found >=5);
            int t = stoi(logs[i].substr(found2+1));
            event newe(t, f, s);
            events.push_back(newe);
        }
        sort(events.begin(), events.end());
        
        // push events in stack if its a starting point, pop event if it ends.
        int timestamp = 0;
        for(auto& e:events) {
            if (e.start) {     //start of an event
                if (!c.empty()) {
                    //event prev = c.top();
                    time[c.top()] += e.time-timestamp;
                }
                timestamp = e.time;
                c.push(e.func);
            } else {          // end of an event
                //End point is the previous time stamp while start is the
                //next tinestamp. We need do +1 here. 
                time[e.func] += e.time-timestamp+1;
                timestamp = e.time+1;
                c.pop();
            }   
            //cout<<timestamp<<" ";
        }
        
        return time;
    }
};
