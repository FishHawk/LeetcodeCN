/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *curr1 = l1, *curr2 = l2, *answer = new ListNode(0);
        ListNode *ret = answer;
        while (curr1 != nullptr || curr2 != nullptr) {
            if (answer->next == nullptr) answer->next = new ListNode(0);
            answer = answer->next;

            if (curr1 != nullptr) {
                answer->val += curr1->val;
                curr1 = curr1->next;   
            }
            if (curr2 != nullptr) {
                answer->val += curr2->val;
                curr2 = curr2->next;   
            }
            if (answer->val >= 10) {
                answer->val -= 10;
                answer->next = new ListNode(1);
            }
        }
        return ret->next;
    }
};
