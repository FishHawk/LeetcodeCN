/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i0] < nums[i]) nums[++i0] = nums[i];
        }
        return ++i0;
    }
};
// @lc code=end
