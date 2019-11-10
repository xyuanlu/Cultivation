/*
 * 716. Max Stack
 */
 
class MaxStack {
public:
    // each element stores the max value we have seen so far
    /** initialize your data structure here. */
    class P{
    public:
        int v;
        int m;
    };
    MaxStack() {
        
    }
    
    void push(int x) {
        int mm = INT_MIN;
        if (_s.empty()) {
            mm = x;
        } else {
            mm = max(x, _s.top().m);
        }
        _s.push({x, mm});
    }
    
    int pop() {
        int v = _s.top().v;
        _s.pop();
        return v;
    }
    
    int top() {
        return _s.top().v;
    }
    
    int peekMax() {
        return _s.top().m;
    }
    
    int popMax() {
        //if (_s.empty()) return;
        int curm = peekMax();
        stack<P> mm;
        while (!_s.empty() && peekMax()==curm) {
            //cout<<_s.top().v<<" "<<_s.top().m<<endl;
            mm.push(_s.top());
            _s.pop();
            if (mm.top().v == mm.top().m)
                break;
        }
        int newm = INT_MIN;
        if(!_s.empty()) 
            newm = peekMax();
        mm.pop();
        while(!mm.empty()) {
            P temp = mm.top();
            mm.pop();
            newm = max(newm, temp.v);
            _s.push({temp.v, newm});
        }
        return curm;
    }
private:
    stack<P> _s;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
