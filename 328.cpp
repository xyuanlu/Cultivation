/*
 * 328. Odd Even Linked List
 *  Given a singly linked list, group all odd nodes (idx) together followed by the even nodes.
 *  Please note here we are talking about the node number and not the value in the nodes.
 *
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode oddH(-1), evenH(-1);
        ListNode *oddcur = &oddH, *evencur = &evenH;
        ListNode *cur = head, *next = cur->next, *curHead = oddcur;
        
        int i=0;
        while(cur != nullptr) {
            ++i;
            if (i%2 == 1) {
                curHead = oddcur;
            } else {
                curHead = evencur;
            }
            next = cur->next;
            curHead->next = cur;
            cur->next = nullptr;
            cur = next;
            if (i%2 == 1) {
                oddcur = oddcur->next;
            } else {
                evencur = evencur->next;
            }
        }
        oddcur->next = evenH.next;
        return oddH.next;
    }
};
