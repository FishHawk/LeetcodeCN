/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        int i0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) nums[i0++] = nums[i];
        }
        return i0;
    }
};
// @lc code=end

