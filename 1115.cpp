/*
* 1115. Print FooBar Alternately
* Modify the given program to output "foobar" n times.
*/

class FooBar {
private:
    int n;
    mutex muF, muB;

public:
    FooBar(int n) {
        this->n = n;
        muB.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            muF.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            muB.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            muB.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            muF.unlock();
        }
    }
};
