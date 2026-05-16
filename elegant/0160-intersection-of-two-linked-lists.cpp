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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        return [headA, headB](this auto self, ListNode *a, ListNode *b) {
            if (a == b) {
                return a;
            }
            return self(a ? a->next : headB, b ? b->next : headA);
        }(headA, headB);
    }
};
