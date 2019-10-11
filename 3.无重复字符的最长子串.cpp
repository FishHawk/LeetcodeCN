/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int curr = 0, max = 0;

        for (auto i = 0; i < s.size(); i++) {
            curr = min(curr + 1, 1 + i - map[s[i]]);
            map[s[i]] = i + 1;
            if (curr > max) max = curr;
        }
        return max;
    }
};
