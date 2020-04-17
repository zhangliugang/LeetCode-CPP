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
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res{};
        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                res += reps[i];
                num -= values[i];
            }
        }
        
        return res;
    }
};

#endif //LEETCODE_INTROMAN_H
