/*
 *  382. Linked List Random Node
 * 
 * Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being chosen.
 *
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you? Could you
 * solve this efficiently without using extra space?
 */
 
 
 
/*
 *        Reservoir sampling
 *  https://en.wikipedia.org/wiki/Reservoir_sampling
 *
 * Suppose we see a sequence of items, one at a time. We want to keep ten items in memory,
 * and we want them to be selected at random from the sequence. If we know the total number of
 * items n, then the solution is easy: select 10 distinct indices i between 1 and n with equal probability,
 * and keep the i-th elements. The problem is that we do not always know the exact n in advance. A possible solution is the following:
 *
 * Keep the first ten items in memory.
 * When the i-th item arrives (for {\displaystyle i>10}{\displaystyle i>10}):
 * with probability {\displaystyle 10/i}{\displaystyle 10/i}, keep the new item (discard an old one, selecting which to replace at random, each with chance 1/10)
 * with probability {\displaystyle 1-10/i}{\displaystyle 1-10/i}, keep the old items (ignore the new one)
*/
 
 
 
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int count=0;
    ListNode *h;
    Solution(ListNode* head) {
        h = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        count = 1;
        int res = h->val;
        ListNode *cur = h->next;
        while (cur!=nullptr) {
            count++;
            int ran = rand() % count+1;
            if(ran==count)
                res = cur->val;
            cur = cur->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
