/*
 * 622. Design Circular Queue
 * 
 * Design your implementation of the circular queue. The circular queue is a linear data
 * structure in which the operations are performed based on FIFO (First In First Out)
 * principle and the last position is connected back to the first position to make a circle.
 * It is also called "Ring Buffer".
 */
 
 class MyCircularQueue {
public:
    // Pop the element at idx begin, write at idx right. 
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        m = vector<int>(k);
        left = 0;
        right = 0;
        size = 0;
        K = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (size == m.size())
            return false;
        m[right%K] = value;
        right++;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size == 0) {
            return false;
        }
        left++;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(size ==0)
            return -1;
        return m[left%K];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(size ==0)
            return -1;
        //cout<<right<<endl;
        return m[(right-1)%K];    //<<------right -1
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == m.size();
    }
private:
    vector<int> m;
    int left, right, size, K;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
