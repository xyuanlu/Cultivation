/*
 * 1114. Print in Order
 * Design a mechanism and modify the program to ensure that second() is executed after first(),
 * and third() is executed after second().
 */

class Foo {
public:
    Foo() {
        mu2.lock();
        mu3.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst(); 
        mu2.unlock();
    }

    void second(function<void()> printSecond) {
        mu2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mu3.unlock();
    }

    void third(function<void()> printThird) {
        mu3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mu3.unlock();
    }
    
private:
     mutex mu2, mu3;
};
