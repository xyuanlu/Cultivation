/*
 * 84. Largest Rectangle in Histogram
 */
 
 class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        // maintain a minitonic increasing stack
        // if heights[i] < s.back()
        // compute every rectangle ends at i-1. Since every bar between s.back and
        // i-1 (includ i-1) should be larger than s.back,
        // and every bar between prev(s.back) and s.back is higher than s.back
        // this rectangle's height is s.back.
        
        stack<int> s;
        s.push(-1);
        heights.push_back(0);
        int res = 0;
        for(int i=0; i<heights.size(); ++i) {
            while(s.top()!=-1 && heights[i] <= heights[s.top()]) {
                // compute the rec ends at i-1;
                int idx = s.top();
                s.pop();
                //cout<<i<<" "<<idx<<" "<<heights[idx]<<endl;
                res = max(res, (i-s.top()-1)*heights[idx]);
            } 
            s.push(i);
        }
        return res;
    }
    
    
    /*
    
    The following is the avg NlogN worest N^2 solution.
    
    class sgTree {
    public:
        int l;
        int r;
        int min;
        int minIdx;
        
        sgTree *left, *right;
        sgTree(int ll, int rr, int m, int mdx):  l(ll), r(rr), min(m), minIdx(mdx) {
            left = nullptr;
            right = nullptr;
        }
        
        ~sgTree(){
            delete left;
            delete right;
        }
        
    };
    
    sgTree* buildT(vector<int> &nums, int l, int r) {
        if (r<=l+1) {
            //cout<<"build" << l<<" "<<r<<endl;
            sgTree *root = new sgTree(l, r, nums[l], l);
            return root;
        }
        //cout<<"build" << l<<" "<<r<<endl;
        sgTree *root = new sgTree(l, r, nums[l], l);
        root->left = buildT(nums, l, (r+l)/2 + (r+l)%2);
        root->right = buildT(nums, (r+l)/2 + (r+l)%2, r);
        int min=nums[l], minIdx = l;
        if (root->left!=nullptr) {
            //cout<<"nnn "<<root->left->l<<" "<<root->left->r<<" "<<root->left->min<<" "<<min<<endl;
            if (root->left->min < min) {
                //cout<<"nnn"<<endl;
                min = root->left->min;
                minIdx = root->left->minIdx;
            }
        }
        if (root->right!=nullptr) {
            if (root->right->min < min) {
                min = root->right->min;
                minIdx = root->right->minIdx;
            }
        }
        root->min = min;
        root->minIdx = minIdx;
        //cout<<"build" << l<<" "<<r<<" "<<min<<endl;
        return root;
    }
    
    // find min using segment tree:
    vector<int> findInSgTree(sgTree *root, int l, int r) {
        //cout<<root->l<<" "<<root->r<<" "<<l<<" "<<r<<endl;
        if (l==root->l && r==root->r ) {
            return vector<int> {root->min, root->minIdx};
        }
        int mid = (root->l+root->r)/2 + (root->l+root->r)%2;
        //cout<<mid<<endl;
        if (r<=mid) {
            return findInSgTree(root->left, l, r);
        }
        if (l>=mid) {
            return findInSgTree(root->right, l, r);
        }
        vector<int> v1 = findInSgTree(root->left, l, mid);
        vector<int> v2 = findInSgTree(root->right, mid, r);
        if (v1[0]<v2[0]) {
            return v1;
        } else {
            return v2;
        }
        
    }
    
    //int largestRectangleArea2(vector<int>& heights) {
        // DC:
         // max rectangle is :
         // 1. shortest bar * whole length   or
         // 2. max rec from left part of the shortest bar   or
         // 3. max rec from the right part
         //
        if (heights.size()==0)
            return 0;
        // build a segTree to find min
        root = buildT(heights, 0, heights.size());
        
        return helper(heights, 0, heights.size());
    }
    
    sgTree *root;
    int helper(vector<int>& heights, int l, int r) {
        if (r<=l) {
            return 0;
        }
        //cout << l << " " << r << endl;
        // find min idx
        
        //int minIdx = l, minVal = heights[l];
        //for(int i=l; i<r; ++i) {
        //    if (heights[i]<minVal) {
        //        minIdx = i;
        //        minVal = heights[i];
        //    }
        //}
        
        vector<int> m = findInSgTree(root, l, r);
        int minIdx = m[1];
        int minVal = m[0];
        
        cout<<"mid: "<<minVal<<" "<<l<<" "<<r<<endl;
        int can1 = minVal * (r-l);
        int can2 = helper(heights, l, minIdx);
        int can3 = helper(heights, minIdx+1, r);
        return max(can1, max(can2, can3));
        
    }
    

    ~Solution(){
        delete root;
    }*/
};

