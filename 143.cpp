/*
 *143. Reorder List
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
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
    void reorderList(ListNode* head) {
        // find middle point
        // reverse last part
        // merge two linked list
        
        if(head == nullptr)
            return;
        ListNode d(-1), d2(-1);
        d.next = head;
        ListNode *dummy1 = &d, *dummy2 = &d2;
        ListNode *l = dummy1, *r = dummy1;
        while(r->next !=nullptr && r->next->next != nullptr) {
            //cout<<l->val<<" "<<r->val<<endl;
            r = r->next->next;
            l = l->next;
        }
        
        dummy2->next = l->next;
        l->next = nullptr;
        
        /*ListNode *t = dummy2;
        while(t!=nullptr) {
            cout<<t->val<<" ";
            t=t->next;
        }
        cout<<endl;
        */
        // reverse second part of the list
        ListNode *hnext = dummy2->next;
        ListNode *cur = hnext->next;
        
        while(cur != nullptr) {
            //cout<<cur->val<<" "<<hnext->val;
            ListNode *next = cur->next;
            ListNode *nn = dummy2->next;
            hnext->next = next;
            dummy2 ->next = cur;
            cur->next = nn;
            //hnext = dummy2->next;
            cur = next;
        }
        /*
        t = dummy2;
        while(t!=nullptr) {
            cout<<t->val<<" ";
            t=t->next;
        }
        cout<<endl;
        */
        
        // merge
        ListNode res(-1);
        cur = &res;
        ListNode *cur1 = dummy1->next, *cur2 = dummy2->next;
        int count = 0;
        while(cur1!=nullptr && cur2!=nullptr) {
            if(count%2 == 0) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
            cur->next = nullptr;
            count++;
        }
        if(cur2!=nullptr) {
            cur->next = cur2;
        }
        //return res.next;
        
    }
    
    
    
};


