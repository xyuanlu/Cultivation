/*
 * 731. My Calendar II
 * No Triple booking
 *
 * A triple booking happens when three events have some non-empty intersection
 * (ie., there is some time that is common to all 3 events.)
 */
 
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it=_overlaps.begin(); it!=_overlaps.end(); ++it) {
            if ((it->second > start && it->first<end))
                return false;
        }
        
        for(auto it=_ints.begin(); it!= _ints.end(); ++it) {
            if (it->first>=end)
                break;
            if ((it->second > start && it->first<end))
                _overlaps[max(it->first, start)] = min(end, it->second);
        } 
        _ints.insert(pair<int, int>(start, end));
        return true;
    }
    
private:
    multimap<int, int, less<int>> _ints;
    map<int, int> _overlaps; // all overlaped intervals
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
