/*
* 588. Design In-Memory File System 
*
*/
class FileSystem {
public:
    class Base{
    public:
        string name;   // does not contarin '/'
        virtual ~Base() {}
    };
    
    class Dir : public Base{
    public:
        Dir(string n) {name = n;}
        // name -> ptr
        map<string, Base*> next;
        
        ~Dir(){
            for (auto &it:next) {
                delete it.second;
            }
        }
    };
    
    class File : public Base{
    public:
        
        File(string n) {name = n;}
        string content;
        
    };
    
    Dir *root;
    FileSystem() {
        root = new Dir("");
    }
    
    vector<string> ls(string path) {
        vector<string> dirs = helper(path);
        vector<string> res;
        Base *cur = root;
        
        for(int i=0; i<dirs.size(); ++i) {
            Dir *d = dynamic_cast<Dir*>(cur);
            if (d->next.find(dirs[i]) == d->next.end()) {
                return res;
            }
            cur = d->next[dirs[i]];
        }

        Dir *d = dynamic_cast<Dir*>(cur);
        //cout<<(d==nullptr)<<endl;
        if (d != nullptr) {
            for (auto &it:d->next) {
                res.push_back(it.second->name);
                //cout<<it.second->name<<endl;
            }
            return res;
        }
        //File *f = dynamic_cast<File*>(cur);
        res.push_back(cur->name);
        return res;
    }
    
    void mkdir(string path) {
        vector<string> dirs = helper(path);
        vector<string> res;
        Base *cur = root;
        
        for(int i=0; i<dirs.size(); ++i) {
            Dir *d = dynamic_cast<Dir*>(cur);
            if (d->next.find(dirs[i]) == d->next.end()) {
                //cout<<"create "<<dirs[i]<<endl;
                d->next[dirs[i]] = new Dir(dirs[i]);
            }
            cur = d->next[dirs[i]];
        }
        
    }
    
    void addContentToFile(string path, string content) {
        vector<string> dirs = helper(path);
        vector<string> res;
        Base *cur = root;
        
        for(int i=0; i<dirs.size(); ++i) {
            Dir *d = dynamic_cast<Dir*>(cur);
            if (d->next.find(dirs[i]) == d->next.end()) {
                if (i != dirs.size()-1 ) {
                    d->next[dirs[i]] = new Dir(dirs[i]);
                }
                else {
                    d->next[dirs[i]] = new File(dirs[i]);
                }
            }
            cur = d->next[dirs[i]];
        }
        
        File *f = dynamic_cast<File*>(cur);
        //if (f==nullptr)
        //    return;
        f->content += content;
    }
    
    string readContentFromFile(string path) {
        vector<string> dirs = helper(path);
        Base *cur = root;
        
        for(int i=0; i<dirs.size(); ++i) {
            Dir *d = dynamic_cast<Dir*>(cur);
            if (d->next.find(dirs[i]) == d->next.end()) {
                return "";
            }
            cur = d->next[dirs[i]];
        }
        
        File *f = dynamic_cast<File*>(cur);
        if (f==nullptr)
            return "";
        return f->content;
    }
    
    ~FileSystem(){
        delete root;
    }
    
private:
    vector<string> helper(string &s) {
        int prev = 0;
        vector<string> res;
        for(int i=1; i<s.size(); ++i) {
            if (s[i]=='/') {
                res.push_back(s.substr(prev+1, i-prev-1));
                prev = i;
            }
        }
        if (prev+1 < s.size())
            res.push_back(s.substr(prev+1, s.size()-prev-1));
        /*cout<<"path  " <<res.size()<<endl;
        for(auto &it:res) {
            cout<<it<<" ";
        }
        cout<<endl;*/
        return res;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
