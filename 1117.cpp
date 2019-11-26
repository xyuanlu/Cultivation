/*
 * 1117. Building H2O
 */
 
 class H2O {
public:
    int readyH;
    int readyO;
    int runningH;
    int runningO;
    condition_variable cv;
    mutex mu;
    
    H2O() {
        readyH = 0;
        readyO = 0;
        runningH = 0;
        runningO = 0;
    }

    void leaving(){
        if (runningH == 2 && runningO == 1) {
            //cout<<"reset"<<endl;
            readyH = 0;
            readyO = 0;
            runningH = 0;
            runningO = 0;
        }
    }
    
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock lk(mu);
        //cout<<"1rH "<<readyH<<endl;
        while(readyH ==2) {
            cv.wait(lk);
        }
        
        readyH++;
        cv.notify_all();          // we may achive 2Hand1O after rH++
        //cout<<"rH "<<readyH<<" "<<readyO<<endl;
        while(readyH !=2 || readyO!=1) {
            cv.wait(lk);
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        //cout<<"HHHHH "<<endl;
        runningH++;
        leaving();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) { 
        unique_lock lk(mu);
        //cout<<"1rO "<<readyO<<endl;
        while(readyO ==1) {
            cv.wait(lk);
        }
        
        readyO++;
        cv.notify_all(); 
        //cout<<"rO "<<readyH<<" "<<readyO<<endl;
        while(readyH !=2 || readyO!=1) {
            cv.wait(lk);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        //cout<<"OOOO "<<endl;
        releaseOxygen();
        runningO++;
        leaving();
        cv.notify_all();
    }
};

