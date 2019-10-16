/*
 * 148. Sort List
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next ==nullptr)   // return if empty or size ==1
            return head;
        // split in half
        ListNode n1(-1), n2(-1);
        n1.next = head;
        ListNode *l = &n1, *r = &n1;
        while (r->next!=nullptr && r->next->next!=nullptr) {
            //cout<<l->val<<" "<<r->val<<endl;
            l = l->next;
            r = r->next->next;
        }
        n2.next = l->next;
        l->next = nullptr;
        
        // sort
        n1.next = sortList(n1.next);
        n2.next = sortList(n2.next);
        
        //cout<<"*"<<endl;
        
        // merge
        ListNode res(-1);
        ListNode *c1 = n1.next, *c2 = n2.next, *c = &res, *next;
        while (c1!=nullptr && c2!=nullptr) {
            //cout<<c1->val <<" "<< c2->val<<endl;
            if (c1->val < c2->val) {
                next = c1->next;
                c->next = c1;
                c1 = next;
            } else {
                next = c2->next;
                c->next = c2;
                c2 = next;
            }
            c->next->next = nullptr;
            c = c->next;
        }
        if (c1!=nullptr) {
            c->next = c1;
        } else if (c2!=nullptr) {
            c->next = c2;
        }
        
        return res.next;
    }
};
