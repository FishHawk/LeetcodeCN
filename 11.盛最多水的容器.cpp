/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_v = 0;
        while (right > left) {
            auto min_h = min(height[left], height[right]);
            max_v = max(max_v, (right - left) * min_h);
            while (height[left] <= min_h && left < right) left++;
            while (height[right] <= min_h && left < right) right--;
        }
        return max_v;
    }
};

