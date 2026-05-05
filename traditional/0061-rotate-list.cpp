/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    static pair<ListNode*, int> getBackAndLen(ListNode* head, int len = 1)
    {
        if (head->next == nullptr) {
            return {head, len};
        }
        return getBackAndLen(head->next, len + 1);
    }

    static ListNode* getNth(ListNode* head, int n)
    {
        if (n == 0) {
            return head;
        }
        return getNth(head->next, n - 1);
    }

public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr) {
            return nullptr;
        }
        const auto [back, len] = getBackAndLen(head);
        const int rot = k % len;
        if (rot == 0) {
            return head;
        }
        const int new_back_i = len - 1 - rot;
        ListNode * const new_back_p = getNth(head, new_back_i);
        ListNode * const new_head_p = new_back_p->next;
        // 下面两处是赋值
        new_back_p->next = nullptr;
        back->next = head;
        return new_head_p;
    }
};
