/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = -1;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j;
        for (j = i + 1; j < nums.size(); j++) {
            if (nums[j] <= nums[i]) break;
        }

        iter_swap(nums.begin() + i, nums.begin() + j - 1);
        sort(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
