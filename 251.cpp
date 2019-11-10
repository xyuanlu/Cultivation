/*
 * 251. Flatten 2D Vector
 */
 
class Vector2D {
public:
    
    Vector2D(vector<vector<int>>& v) {
        for (int i=0; i<v.size(); ++i) {
            for (int j=0; j<v[i].size(); ++j) {
                m.push_back(v[i][j]);
            }
        }
        idx = 0;   
    }
    
    int next() {
        return m[idx++];
        //idx++;
    }
    
    bool hasNext() {
        return idx != m.size();
    }
    
    ~Vector2D(){
        idx=0;
        m.clear();
    }
private:
    vector<int> m;
    int idx;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
