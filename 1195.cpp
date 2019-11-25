/*
 * 1195. Fizz Buzz Multithreaded
 * 
 * If the number is divisible by 3, output "fizz".
 * If the number is divisible by 5, output "buzz".
 * If the number is divisible by both 3 and 5, output "fizzbuzz".
 * Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz
 * will be passed to four different threads:
 */
 
 class FizzBuzz {
private:
    int n, c;
    mutex m;
    std::condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        c=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true) {
            std::unique_lock lk(m);
            //cout<<"1 "<<c<<endl;
            while (c<=n && ! (c%3==0 && c%5!=0)) {
                cv.wait(lk);
            }
            if(c>n) return;
            printFizz();
            c++;
            cv.notify_all();
        }   
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true) {
             std::unique_lock lk(m);
             //cout<<"2 "<<c<<endl;
             while (c<=n && ! (c%5==0 && c%3!=0)) {
                cv.wait(lk);
             }
            if(c>n) return;
            printBuzz();
            c++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            std::unique_lock lk(m);
            //cout<<"3 "<<c<<endl;
            while (c<=n && !(c%3==0 && c%5==0)) {
                cv.wait(lk);
            }
            if(c>n) return;
            printFizzBuzz();
            c++;
            cv.notify_all();        
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true) {
            std::unique_lock lk(m);
            while (c<=n && !(c%3!=0 && c%5!=0)) {
                //cout<<"d "<<c<<endl;
                cv.wait(lk);
            }
            if(c>n) return;
            //cout<<"d "<<c<<endl;
            printNumber(c);
            c++;
            //cout<<"d "<<c<<endl;
            cv.notify_all();    
        }
        
    }
};
