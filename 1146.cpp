/*
 * 1146. Snapshot Array
 */
class SnapshotArray {
public:
    // do it like vm linked clone
    vector<int> cur;    
    vector<map<int, int>> sp;
    int ver;
    int len;
    // diety bit
    unordered_set<int> changed;
    
    SnapshotArray(int length) {
        len = length;
        cur = vector<int>(length, 0);
        sp = vector<map<int, int>>(length, map<int, int>());
        ver = 0;
    }
    
    void set(int index, int val) {
        cur[index] = val;
        changed.insert(index);
    }
    
    int snap() {
        for(auto i:changed) {
            if (sp[i].size()==0 || sp[i].rbegin()->second != cur[i]) {
                sp[i][ver] = cur[i];
            }
        }
        ver++;
        changed.clear();
        return ver-1;
    }
    
    int get(int i, int snap_id) {
        auto it = sp[i].upper_bound(snap_id);
        //assert(it!=sp[i].begin());
        if (it == sp[i].begin()) {
            return 0;
        }
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
