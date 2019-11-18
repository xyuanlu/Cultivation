/*
 * 950. Reveal Cards In Increasing Order
 */
 
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& A) {
        deque<int> dq;
        sort(A.begin(), A.end());
        
        dq.push_back(A[A.size()-1]);
        for(int i=A.size()-2; i>=0; --i) {
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
            dq.push_front(A[i]);
        }
        
        vector<int> res;
        while(!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        
        return res;
    }
};
