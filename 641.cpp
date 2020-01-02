/*
 * 641. Design Circular Deque
 */
 
 class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        K = k;
        size = 0;
        l =1;
        r = -1;
        m = vector<int>(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size == K)
            return false;
        l = (l-1+K) %K;
        m[l] = value;
        if (size==0)
            r = l;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == K)
            return false;
        r = (r+1+K) %K;
        m[r] = value;
        if (size==0)
            l = r;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0)
            return false;
        l = (l+1+K) %K;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0)
            return false;
        r = (r-1+K) %K;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (size==0) return -1;
        return m[l];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (size==0) return -1;
        return m[r];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size==K;
    }
    
private:
    // l and r is the first valid idx
    int l, r;
    int K;
    int size;
    vector<int> m;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
