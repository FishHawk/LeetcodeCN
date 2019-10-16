/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int quotient = 0;
        unsigned int u_dividend = dividend, u_divisor = divisor;
        u_dividend = u_dividend >= (1UL << 31) ? UINT_MAX - u_dividend + 1 : u_dividend;
        u_divisor = u_divisor >= (1UL << 31) ? UINT_MAX - u_divisor + 1 : u_divisor;

        int start = 31;
        for (int start = 31; start >= 0; start--) {
            if (((u_dividend >> start) & 0x00000001) > 0) {
                break;
            }
        }

        unsigned int x = 0;
        for (int i = start; i >= 0; i--) {
            x = (x << 1) | ((u_dividend >> i) & 0x00000001);
            if (x >= u_divisor) {
                x -= u_divisor;
                quotient = (quotient << 1) | 1;
            } else {
                quotient = (quotient << 1);
            }
        }

        if (((dividend ^ divisor) & 0x80000000) == 0) {
            if (quotient >= (1UL << 31) - 1)
                return INT_MAX;
            else
                return quotient;
        } else {
            if (quotient >= (1UL << 31))
                return INT_MIN;
            else
                return -quotient;
        }
    }
};
// @lc code=end
