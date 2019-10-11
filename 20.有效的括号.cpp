/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (auto &c : s) {
            if (c == '(')
                brackets.push(')');
            else if (c == '{')
                brackets.push('}');
            else if (c == '[')
                brackets.push(']');
            else if (brackets.empty() || brackets.top() != c)
                return false;
            else
                brackets.pop();
        }
        return brackets.empty();
    }
};
// @lc code=end
