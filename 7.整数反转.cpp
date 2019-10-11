/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int x) {
        long reverse_x = 0;
        while (x != 0) {
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }
        return (reverse_x > INT_MAX || reverse_x < INT_MIN) ? 0 : reverse_x; 
    }
};

