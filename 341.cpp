/*
341. Flatten Nested List Iterator

  Given a nested list of integers, implement an iterator to flatten it.

  Each element is either an integer, or a list -- whose elements may also be integers or other lists.

  Example 1:

  Input: [[1,1],2,[1,1]]
  Output: [1,1,2,1,1]
  Explanation: By calling next repeatedly until hasNext returns false, 
               the order of elements returned by next should be: [1,1,2,1,1].

*/


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    /*
     * Push and pop in next(). 
     * Handle when i==cur vector.size(), previous idx++. and can also hit size().
     * We should have a while pop 
    */
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(nestedList.size()==0)
            return;
        nls.push(nestedList);
        s.push(0);
    }

    int next() {
        
        //cout<<s.top()<<" "<<nls.size()<<endl;
        int res = nls.top()[s.top()].getInteger();
        //cout<<res<<endl;
        s.top()++;
        while(!s.empty() && s.top() == nls.top().size()) {
            nls.pop();
            s.pop();
            if(!s.empty())
                s.top()++;
            //cout<<s.size()<<" "<<nls.size()<<endl;
        }
        
        return res;
    }

    bool hasNext() {
        while(!s.empty() && !nls.top()[s.top()].isInteger()) {
            vector<NestedInteger>& n = nls.top()[s.top()].getList();
            if(n.size()==0){
                s.top()++;
                while(!s.empty() && s.top() == nls.top().size()) {   <<------
                    nls.pop();
                    s.pop();
                    if(!s.empty())
                        s.top()++;
                    //cout<<s.size()<<" "<<nls.size()<<endl;
                }
                continue;
            }
            nls.push(n);
            s.push(0);
        }
        return !nls.empty();
    }
private:
    stack<vector<NestedInteger>> nls;
    stack<int> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
