/*
 * 142. Linked List Cycle II
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 * 
 * Note: Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
        if (head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode d(-1);
        d.next = head;
        ListNode *l = &d, *r = &d;
        
        while (r->next!=nullptr && r->next->next!=nullptr) {
            l = l->next;
            r = r->next->next;
            if (l==r) {
                break;
            }
        }
        
        l = &d;
        while(l!=r && r!=nullptr) {
            l = l->next;
            r = r->next;
        }
        return r;
    }
};
