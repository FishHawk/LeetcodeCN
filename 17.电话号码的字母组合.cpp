/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return vector<string>();
        unordered_map<char, string> key_map{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        int combination_size = 1;
        for (auto &d : digits) {
            combination_size *= key_map[d].length();
        }

        vector<string> combination(combination_size, string());
        for (auto &s : combination) {
            s.reserve(digits.length());
        }

        int loop1 = combination_size;
        int loop2;
        for (auto &d : digits) {
            string possible_c = key_map[d];
            loop2 = combination_size / loop1;
            loop1 /= possible_c.length();

            int index = 0;
            for (int i = 0; i < loop2; i++) {
                for (auto &c : possible_c) {
                    for (int j = 0; j < loop1; j++) {
                        combination[index].push_back(c);
                        index++;
                    }
                }
            }
        }

        return combination;
    }
};
// @lc code=end
