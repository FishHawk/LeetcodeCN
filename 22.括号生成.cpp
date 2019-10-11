/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void add_one_bracket(vector<string>& parenthesis, string str, int nl, int nr, int n) {
        if (nl == n && nr == n) {
            parenthesis.push_back(str);
            return;
        }
        if (nl < n) add_one_bracket(parenthesis, str + '(', nl + 1, nr, n);
        if (nl > nr) add_one_bracket(parenthesis, str + ')', nl, nr + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        if (n > 0) add_one_bracket(parenthesis, "", 0, 0, n);
        return parenthesis;
    }
};
// @lc code=end
