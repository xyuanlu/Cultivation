/*
Create a timebased key-value store class TimeMap, that supports two operations.

  1. set(string key, string value, int timestamp)

  Stores the key and value, along with the given timestamp.
  2. get(string key, int timestamp)

  Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
  If there are multiple such values, it returns the one with the largest timestamp_prev.
  If there are no values, it returns the empty string ("").
*/

class TimeMap {
public:
    /** Initialize your data structure here. */
    /*
     * How to find the largest smaller idx using lower_bound
     *  (or upper_bound depending on if we can do ==)
     */
    /* <key, <time, key>>  
     *  <time, key> is stored in map in acceding order. Since we need to fine
     *  t <= given T. we could do upper_bound-- and check if it is valid.  
     */
    map<string, map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]= value;
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())
            return "";
        auto it = m[key].upper_bound(timestamp);
        if(it != m[key].begin()) {
            it--;
            return it->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
