/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        long number = 0;
        bool is_negative = false;
        for (auto i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                if (str[i] == '+') i++;
                else if (str[i] == '-') {is_negative = true; i++;}

                while (str[i]>='0' && str[i] <= '9' && i < str.size()) {
                    number = number * 10 + (str[i] - '0');
                    if (number > INT_MAX) return is_negative ? INT_MIN : INT_MAX; 
                    i++;
                }
                return is_negative ? -number : number;
            }
        }
        return 0;
    }
};

