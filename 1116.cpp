/*
 * 1116. Print Zero Even Odd
 */
 
 class ZeroEvenOdd {
private:
    int n;
    int cur;
    int z;
    condition_variable cv;
    mutex mu;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cur = 1;
        z = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        {
            unique_lock lk(mu);
            while(!z) {
                cv.wait(lk);
            }
            //cout<<"0"<<endl;
            printNumber(0);
            z = false;
            cv.notify_all();
            if (cur>=n)
                return;
        }
        
        zero(printNumber);
    }

    void even(function<void(int)> printNumber) {
        if (n<2)
            return;
        {
            unique_lock lk(mu);
            while(z || cur%2==1) {
                cv.wait(lk);
            }
            if (cur>n)
                return;
            //cout<<cur<<endl;
            printNumber(cur);
            z = true;
            cur++;
            cv.notify_all();
            if (cur>=n)
                return;
        }
        even(printNumber);
    }

    void odd(function<void(int)> printNumber) {
        {
            unique_lock lk(mu);
            while(z || cur%2==0) {
                cv.wait(lk);
            }
            //cout<<cur<<endl;
            printNumber(cur);
            z = true;
            cur++;
            cv.notify_all();
        
            if (cur>=n)
                return;
        }
        odd(printNumber);
        
    }
};
