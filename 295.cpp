/*
 * 295. Find Median from Data Stream
 */
 
 class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> first_part;
    priority_queue<int, vector<int>, std::greater<int>> second_part;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first_part.size() ==0 || num <= first_part.top()) {
            first_part.push(num);
        } else {
            second_part.push(num);
        }
        if(first_part.size() > second_part.size()+1) {
            int temp = first_part.top();
            first_part.pop();
            second_part.push(temp);
        }
        if(second_part.size() > first_part.size()+1) {
            int temp = second_part.top();
            second_part.pop();
            first_part.push(temp);
        } 
    }
    
    double findMedian() {
        if(first_part.size() == second_part.size()) {
            return double(first_part.top() + second_part.top())/2;
        }   
        if (first_part.size() > second_part.size()) {
            return first_part.top();
        } else {
           return second_part.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
