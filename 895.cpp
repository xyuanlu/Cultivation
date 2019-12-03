/*
 * 895. Maximum Frequency Stack
 * Implement FreqStack, a class which simulates the operation of a stack-like data structure.
 *
 * FreqStack has two functions:
 *
 * push(int x), which pushes an integer x onto the stack.
 * pop(), which removes and returns the most frequent element in the stack.
 * If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 *
 */
 
class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (vf.count(x)!=0) {
            int f = vf[x];
            //cout<<"we have "<<f<<" "<<x<<endl;
            vf[x]++;
            fc[f]--;
            fc[f+1]++;
        } else {
            vf[x]++;
            fc[1]++;
        }
    }
    
    int pop() {
        int maxF = fc.rbegin()->first;
        //cout<<"fre "<<maxF<<endl;
        stack<int> ss;
        while(vf[s.top()] != maxF) {
            //cout<<s.top()<<" "<<maxF<<endl;
            ss.push(s.top());
            s.pop();
        }
        int res = s.top();
        s.pop();
        
        vf[res]--;
        fc[maxF]--;
        fc[maxF-1]++;
        
        //cout<<"new maxF count "<<fc[maxF]<<endl;
        if (fc[maxF] ==0) {
            fc.erase(maxF);
        }
        while(!ss.empty()) {
            s.push(ss.top());
            ss.pop();
        }
        //cout<<res<<endl;
        return res;
    }
private:
    // freq count
    map<int, int> fc;
    // val -> freq
    map<int, int> vf;
    stack<int> s;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
