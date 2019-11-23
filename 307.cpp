/*
* 307. Range Sum Query - Mutable
* Segment tree
*/

class NumArray {
public:
    class sgTree {
    public:
        int l;
        int r;
        int sum;
        
        sgTree *left, *right;
        sgTree(int ll, int rr, int m):  l(ll), r(rr), sum(m) {
            left = nullptr;
            right = nullptr;
        }
        
        ~sgTree(){
            delete left;
            delete right;
        }
        
    };
    
    sgTree* buildT(vector<int> &nums, int l, int r) {
        if (r<=l) {
            return nullptr;
        }
        if (r==l+1) {
            //cout<<"build" << l<<" "<<r<<endl;
            sgTree *root = new sgTree(l, r, nums[l]);
            return root;
        }
        sgTree *root = new sgTree(l, r, 0);
        root->left = buildT(nums, l, (r+l)/2 + (r+l)%2);
        root->right = buildT(nums, (r+l)/2 + (r+l)%2, r);
        
        if (root->left != nullptr)
            root->sum += root->left->sum;
        if (root->right != nullptr) 
            root->sum += root->right->sum;
        //cout<<"build" << l<<" "<<r<<" "<<root->sum<<endl;
        return root;
    }
    
    // find min using segment tree:
    int findInSgTree(sgTree *root, int l, int r) {
        //cout<<root->l<<" "<<root->r<<" "<<l<<" "<<r<<endl;
        if (l==root->l && r==root->r ) {
            return root->sum;
        }
        int mid = (root->l+root->r)/2 + (root->l+root->r)%2;
        //cout<<mid<<endl;
        if (r<=mid) {
            return findInSgTree(root->left, l, r);
        }
        if (l>=mid) {
            return findInSgTree(root->right, l, r);
        }
        int s1 = findInSgTree(root->left, l, mid);
        int s2 = findInSgTree(root->right, mid, r);
        return s1 + s2;
        
    }
    
    void updateSgTree(sgTree *root, int idx, int preVal, int newVal) {
        root->sum = root->sum - preVal +newVal;
        //cout<<"up "<<root->l<<" "<<root->r<<" "<<root->sum<<endl;
        if (idx==root->l && idx+1==root->r ) {
            return;
        }
        int mid = (root->l+root->r)/2 + (root->l+root->r)%2;
        //cout<<mid<<endl;
        if (idx<mid) {
            updateSgTree(root->left, idx, preVal, newVal);
        }
        if (idx>=mid) {
            updateSgTree(root->right, idx, preVal, newVal);
        }
    }
    
    
    NumArray(vector<int>& nums) {
        _nums = nums;
        root = buildT(nums, 0, nums.size());
    }
    
    void update(int i, int val) {
        updateSgTree(root, i, _nums[i], val);
        _nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return findInSgTree(root, i, j+1);
    }
    
    ~NumArray(){
        delete root;
    }
    
    
private:
    sgTree *root;
    vector<int> _nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
