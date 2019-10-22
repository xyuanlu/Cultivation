/*
 * 1019. Next Greater Node In Linked List
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    class P{
    public:
        int val;
        int idx;
    };
    
    vector<int> nextLargerNodes(ListNode* head) {
        /*
         * hint: We can use a stack that stores nodes in monotone decreasing
         * order of value. When we see a node_j with a larger value, every
         * node_i in the stack has next_larger(node_i) = node_j .
         */
        stack<P> m;
        vector<int> res;
        ListNode* cur = head;
        int idx = 0;
        while(cur!=nullptr) {
            if (m.size()==0 || cur->val <= m.top().val) {
                m.push({cur->val, idx});
                idx++;
                res.push_back(-1);
                cur = cur->next;
            } else {       //m.size()!=0 && cur->val > m.top().val
                res[m.top().idx] = cur->val;
                m.pop();
                continue;
            }
        }
        
        while(!m.empty()) {
            P t = m.top();
            res[t.idx] = 0;
            m.pop();
        }
        
        return res;
    }
};
