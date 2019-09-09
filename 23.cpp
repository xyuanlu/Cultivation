
/*
 * 23. Merge k Sorted Lists
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
    struct cmp{
        bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val > n2->val;
        }
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode *n : lists) {
            if (n!=nullptr) {
                pq.push(n);
            }
        }
        // Create dummy node on stack.
        ListNode head(-1);
        ListNode *cur = &head;
        
        while(!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            cur->next = temp;
            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
            cur = cur->next;
        }
        
        return head.next;
    }
};
