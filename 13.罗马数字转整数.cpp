/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            switch (s[i]) {
                case 'I': number += 1; break;
                case 'V': if (i != 0 && s[i - 1] =='I') {number += 4; i--;} else number += 5; break;
                case 'X': if (i != 0 && s[i - 1] =='I') {number += 9; i--;} else number += 10; break;
                case 'L': if (i != 0 && s[i - 1] =='X') {number += 40; i--;} else number += 50; break;
                case 'C': if (i != 0 && s[i - 1] =='X') {number += 90; i--;} else number += 100; break;
                case 'D': if (i != 0 && s[i - 1] =='C') {number += 400; i--;} else number += 500; break;
                case 'M': if (i != 0 && s[i - 1] =='C') {number += 900; i--;} else number += 1000; break;
            }
        }
        return number;
    }
};

