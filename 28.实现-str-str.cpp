/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    std::vector<int> cal_jump_table(string needle) {
        std::vector<int> jump_table{0};
        jump_table.reserve(needle.length());

        int i = 0, j = 1;
        while (j < needle.length()) {
            if (needle[i] == needle[j]) {
                i++;
                j++;
                jump_table.push_back(i);
            } else if (i == 0) {
                j++;
                jump_table.push_back(i);
            } else {
                i = jump_table[i - 1];
            }
        }
        return jump_table;
    }

    int
    strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;

        auto jump_table = cal_jump_table(needle);
        int i = 0, j = 0;
        while (i + needle.length() <= haystack.length()) {
            if (haystack[i + j] == needle[j]) {
                j++;
                if (j == needle.length()) return i;
            } else if (j == 0) {
                i++;
            } else {
                i += j - jump_table[j - 1];
                j = jump_table[j - 1];
            }
        }
        return -1;
    }
};
// @lc code=end
