/*
 * 732. My Calendar III
 *
 * A K-booking happens when K events have some non-empty intersection
 * (ie., there is some time that is common to all K events.)
 *
 * For each call to the method MyCalendar.book, return an integer K representing
 * the largest integer such that there exists a K-booking in the calendar.
 */
 
class MyCalendarThree {
public:
    MyCalendarThree() {
        _his = 0;
    }
    
    int book(int start, int end) {
        int count=0, res = 1;
        _intvCount[start] ++;
        _intvCount[end] --;
        for(auto it=_intvCount.begin(); it!=_intvCount.end(); ++it) {
            if (it->first>=end)
                break;
            count += it->second;
            if (it->first>=start) {
                res = max(res, count);
            }
        }
        _his =  max(res, _his);
        return _his;
    }
    
    map<int, int> _intvCount;  // point -> numebr of intervals happening here
    int _his;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
