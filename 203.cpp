/*
 * 203. Remove Linked List Elements
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode n(-1);
        n.next = head;
        ListNode *cur = &n;
        while(cur!=nullptr && cur->next != nullptr) {
            if (cur->next->val==val) {
                ListNode* next = cur->next->next;
                delete cur->next;
                cur->next = next;
            } else {
                cur = cur->next;
            }
        }
        return n.next;
    }
};
