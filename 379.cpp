/*
 * 379. Design Phone Directory
 *
 * Design a Phone Directory which supports the following operations:
 *
 * get: Provide a number which is not assigned to anyone.
 * check: Check if a number is available or not. 
 * release: Recycle or release a number.
 */
 
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    vector<bool> m;
    int idx;
    int count;
    /*
     * Every time when we get a request for 'get', check the next available slot from
     * position 'idx'. Return the first available。
     */
    
    
    PhoneDirectory(int maxNumbers) {
        m = vector<bool> (maxNumbers, false);
        idx = 0;
        count = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (count == m.size())
            return -1;
        int M = m.size();
        for(int i=0; i<M; ++i) {
            int t = (i+idx)%M;
            if (m[t] == false) {
                m[t] = true;
                count++;
                idx++;
                return t%M;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !m[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        count--;
        m[number] = false;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
