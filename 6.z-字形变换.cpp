/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
class Solution {
public:
    string convert(string s, int num_rows) {
        if (num_rows == 1) return s;

        string result;
        result.reserve(s.size());

        int num_z = 2 * num_rows - 2;

        for (auto i = 0; i < num_rows; i++) {
            for (auto j = i; j < s.size(); j += num_z) {
                result.push_back(s[j]);
                int j2 = j - i + num_z - i;
                if (i != 0 && i != num_rows - 1 && j2 < s.size())
                    result.push_back(s[j2]);
            }
        }
        return result;
    }
};

