/*
 * 232. Implement Queue using Stacks
 */
 
 class MyQueue {
public:
    
    //reverse only when needed, use a reversed flag 
    
    /** Initialize your data structure here. */
    MyQueue() {
        rev = false;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(rev) {
            while(!rs.empty()) {
                s.push(rs.top());
                rs.pop();
            }
            rev = !rev;
        }
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!rev) {
            while(!s.empty()) {
                rs.push(s.top());
                s.pop();
            }
            rev = !rev;
        }
        int res = rs.top();
        rs.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(!rev) {
            while(!s.empty()) {
                rs.push(s.top());
                s.pop();
            }
            rev = !rev;
        }
        return rs.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty() && rs.empty();
    }
    
private:
    stack<int> s, rs;
    bool rev;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
