/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *ps = head, *pe = head, *ps_pre = dummy;

        while (pe != nullptr) {
            for (int i = 0; i < k - 1; i++) {
                pe = pe->next;
                if (pe == nullptr) {
                    auto ret = dummy->next;
                    delete dummy;
                    return ret;
                }
            }

            auto p0 = ps_pre, p1 = ps, p2 = ps->next;

            ps_pre->next = pe;
            ps_pre = ps;
            ps->next = pe->next;
            ps = pe->next;
            pe = ps;

            for (int i = 0; i < k - 1; i++) {
                p0 = p1;
                p1 = p2;
                p2 = p2->next;
                p1->next = p0;
            }
        }

        auto ret = dummy->next;
        delete dummy;
        return ret;
    }
};
// @lc code=end
