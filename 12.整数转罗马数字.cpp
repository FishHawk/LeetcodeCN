/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
class Solution {
public:
    string intToRoman(int num) {
        array<int, 7> roman_values = {1000, 500, 100, 50, 10, 5, 1};
        array<int, 7> roman_symbols_number;
        for (auto i = 0; i < 7; i++) {
            roman_symbols_number[i] = num / roman_values[i];
            num -= roman_symbols_number[i] * roman_values[i];
        }

        array<char, 7> roman_symbols = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        string roman_string;
        for (auto i = 0; i < 7; i++) {
            if ((i == 1 || i == 3 || i == 5) && roman_symbols_number[i + 1] == 4) {
                roman_symbols_number[i + 1] = 0;
                if (roman_symbols_number[i] == 0) {
                    roman_string.push_back(roman_symbols[i + 1]);
                    roman_string.push_back(roman_symbols[i]);
                } else {
                    roman_string.push_back(roman_symbols[i + 1]);
                    roman_string.push_back(roman_symbols[i - 1]);
                    roman_symbols_number[i] = 0;
                } 
            }
            roman_string.append(roman_symbols_number[i], roman_symbols[i]);
        }
        return roman_string;
    }
};

