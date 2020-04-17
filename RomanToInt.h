//
// Created by August on 4/17/20.
//

#ifndef LEETCODE_ROMANTOINT_H
#define LEETCODE_ROMANTOINT_H

/**
 * 13. 罗马数字转整数
 * https://leetcode-cn.com/problems/roman-to-integer/
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        auto map = unordered_map<char, int>{
            {'M',1000},
            {'D',500},
            {'C',100},
            {'L',50},
            {'X',10},
            {'V',5},
            {'I',1}
        };

        int res = 0;
        for (int i = 0; i < s.size(); ) {
            if (i < s.size() - 1  && map[s[i]] < map[s[i+1]]) {
                res -= map[s[i]];
            } else {
                res += map[s[i]];
            }
        }
        return res;
    }
};

#endif //LEETCODE_ROMANTOINT_H
