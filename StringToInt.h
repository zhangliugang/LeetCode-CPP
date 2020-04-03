//
// Created by August on 4/3/20.
//

#ifndef LEETCODE_STRINGTOINT_H
#define LEETCODE_STRINGTOINT_H

/**
 * 8. 字符串转换整数 (atoi)
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

#include <string>

using namespace std;

class StringToInt {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;

        auto flag = false;
        auto negative = false;
        int64_t a = 0;

        for (auto &c : str) {
            if (c == ' ' && !flag) {
                continue;
            }
            else if (c == '-' && !flag) { negative = true; flag = true; }
            else if (c == '+' && !flag) { flag = true; }
            else if (c >= 48 && c <= 57) {
                 flag = true;
                a = a * 10 + (c - 48);
                if (a >= 2147483648) break;
            } else break;
        }
        if (negative) a = -a;

        if (a > 2147483647) return 2147483647;
        if (a < -2147483648) return -2147483648;

        return a;
    }
};

#endif //LEETCODE_STRINGTOINT_H
