/*
 * 1188. Design Bounded Blocking Queue
 */
 
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        N = capacity;
    }
    
    void enqueue(int element) {
        unique_lock lk(mu);
        while(q.size()==N) {
            cv.wait(lk);
        }
        q.push(element);
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock lk(mu);
        while(q.size()==0) {
            cv.wait(lk);
        }
        int res = q.front();
        q.pop();
        cv.notify_all();
        return res;
    }
    
    int size() {
        mu.lock();
        return q.size();
        mu.unlock();
    }
private:
    mutex mu;
    int N;
    queue<int> q;
    condition_variable cv;
};
