/*
 * 82. Remove Duplicates from Sorted List II
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        int prev = -1;
        ListNode dh(-1);
        ListNode *cur = head, *next = head->next, *nn = &dh;
        while(cur != nullptr) {
            next = cur->next;
            if ((cur!=head && cur->val == prev)||
                (next!=nullptr && cur->val == next->val)) {
                prev = cur->val;
                cur = next;
                continue;
            }
            prev = cur->val;
            nn->next = cur;
            cur->next = nullptr;
            nn = cur;
            cur = next;
        }
        return dh.next;
    }
};
