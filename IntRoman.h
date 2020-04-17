//
// Created by August on 4/17/20.
//

#ifndef LEETCODE_INTROMAN_H
#define LEETCODE_INTROMAN_H

/**
 * 12. 整数转罗马数字
 * https://leetcode-cn.com/problems/integer-to-roman/
 */

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res{};
        int a = num / 1000;
        int b = (num - a * 1000) / 100;
        int c = (num - a * 1000 - b * 100) / 10;
        int d = num - a * 1000 - b * 100 - c * 10;
        if (a > 0) {
            res += roman(a, 4);
        }
        if (b > 0) {
            res += roman(b, 3);
        }
        if (c > 0) {
            res += roman(c, 2);
        }
        if (d > 0) {
            res += roman(d, 1);
        }
        return res;
    }

    string roman(int n, int w) {
        switch (w) {
            case 4: {
                return string(n, 'M');
            }
            case 3: {
                if (n == 9) {
                    return "CM";
                } else if (n >= 5) {
                    return "D" + string(n - 5, 'C');
                } else if (n == 4) {
                    return "CD";
                } else {
                    return string(n, 'C');
                }
            }
            case 2: {
                if (n == 9) {
                    return "XC";
                } else if (n >= 5) {
                    return "L" + string(n - 5, 'X');
                } else if (n == 4) {
                    return "XL";
                } else {
                    return string(n, 'X');
                }
            }
            case 1: {
                if (n == 9) {
                    return "IX";
                } else if (n >= 5) {
                    return "V" + string(n - 5, 'I');
                } else if (n == 4) {
                    return "IV";
                } else {
                    return string(n, 'I');
                }
            }
        }
        return "";
    }
};

#endif //LEETCODE_INTROMAN_H
