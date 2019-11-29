/*
 * 729. My Calendar I
 * Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.
 *
 * Your class will have the method, book(int start, int end). Formally, this represents a booking on =
 * the half open interval [start, end), the range of real numbers x such that start <= x < end.
 *
 * A double booking happens when two events have some non-empty intersection
 * (ie., there is some time that is common to both events.)
 * 
 * For each call to the method MyCalendar.book, return true if the event can be added
 * to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 * 
 * Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
 */
 
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        // find if there is any intersection with the 'start'
        auto it1 = _intervals.upper_bound(start);
        if (it1 != _intervals.begin()) {
            it1 --;
            if (start == 79) 
                cout<<"1 "<<it1->first<<" "<<it1->second<<endl;
            if (it1->second > start)
                return false;
        }
        // If there is any intersection with end
        auto it2 = _intervals.lower_bound(end);
        if (it2 != _intervals.begin()) {
            it2 --;
            //cout<<"2 "<<it2->first<<" "<<it2->second<<endl;
            if (it2->first >= start)
                return false;
        }
        // no need to merge
        _intervals[start] = end;
        return true;
    }
private:
    map<int, int> _intervals;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
