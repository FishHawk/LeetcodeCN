/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p_ahead = head, *p_curr = head;
        for (int i = 0; i < n; i++) {
            if (p_ahead == nullptr)
                return head;
            p_ahead = p_ahead->next;
        }

        if (p_ahead == nullptr) {
            head = head->next;
            delete p_curr;
            return head;
        }
        p_ahead = p_ahead->next;

        while (p_ahead != nullptr) {
            p_ahead = p_ahead->next;
            p_curr = p_curr->next;
        }
        auto p_delete = p_curr->next;
        p_curr->next = p_curr->next->next;
        delete p_delete;
        return head;
    }
};
// @lc code=end
