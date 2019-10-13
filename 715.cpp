/*
 * 715. Range Module
 * A Range Module is a module that tracks ranges of numbers. Your task is to design
 * and implement the following interfaces in an efficient manner.
 *
 */
 
class RangeModule {
public:
    // key-valie pair of [begin, end)
    
    map<int, int> m;
    
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = m.upper_bound(right);
              
        if (it!=m.begin()) {
            auto it1 = prev(it);
            right = max(it1->second, right);
            while (it1->second >= left) {
                left = min(left, it1->first);
                //cout<<"erase "<<it1->first<<"-"<<it1->second<<" "<<left<<endl;
                it1 = m.erase(it1);
                if (it1 == m.begin())
                    break;
                it1 -- ;
                
            }
        }
        m[left] = right;
        /*for (auto it:m) {
            cout<<it.first<<" "<<it.second<<"; ";
        }
        cout<<endl;*/
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(right);
              
        if (it!=m.begin()) {
            it--;
        } else {
            return false;
        }
        if (it->first<=left && it->second>=right)
            return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = m.lower_bound(right);
        // second part
        int right2= -1, left2=0;
        // first part
        int right1 = -1, left1 = 0;
        
        if (it!=m.begin()) {
            auto it1 = prev(it);
            // the second part
            if (it1->second > right) {
                right2 = it1->second;
                left2 = right;
                //m[left2] = right2;
            }
            
            // first part
            while (it1->second > left) {
                right1 = min(it1->second, left);
                left1 = it1->first;
                it1 = m.erase(it1);
                if(it1 == m.begin())
                    break;
                it1 -- ;
            }
            if (left2<=right2)
                m[left2] = right2;
        }
        if (left1<=right1)
            m[left1] = right1;
        /*cout<<"--"<<endl;
        for (auto it:m) {
            cout<<it.first<<" "<<it.second<<"; ";
        }
        cout<<endl;*/
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
