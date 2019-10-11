/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        auto p1 = head;
        if (p1 == nullptr) return head;
        auto p2 = head->next;
        if (p2 == nullptr) return head;

        head = p2;
        while (p2->next != nullptr && p2->next->next != nullptr) {
            auto p3 = p2->next;
            auto p4 = p3->next;
            p2->next = p1;
            p1->next = p4;
            p1 = p3;
            p2 = p4;
        }
        auto p3 = p2->next;
        p2->next = p1;
        p1->next = p3;
        return head;
    }
};
// @lc code=end
