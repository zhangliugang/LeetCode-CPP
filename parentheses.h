//
// Created by August on 4/2/20.
//

#ifndef LEETCODE_PARENTHESES_H
#define LEETCODE_PARENTHESES_H

/**
 * 1111. 有效括号的嵌套深度
 * https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
 */

#include <vector>
#include <string>

using namespace std;

class Parentheses {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res = {};
        vector<int> temp = {};
        int i = 0;
        for (char c : seq) {
            if (c == '(') {
                res.push_back(i % 2);
                i++;
            } else {
                i--;
                res.push_back(i % 2);
            }
        }
        return res;
    }
};

#endif //LEETCODE_PARENTHESES_H
