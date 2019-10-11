/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    void swap(ListNode*& a, ListNode*& b) {
        ListNode* temp = a;
        a = b;
        b = temp;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;

        if (l1->val > l2->val) swap(l1, l2);
        auto head = l1;

        while (l2 != nullptr) {
            while (l1->next != nullptr && l1->next->val <= l2->val) {
                l1 = l1->next;
            }
            swap(l1->next, l2);
        }
        return head;
    }
};
// @lc code=end
