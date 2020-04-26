//
// Created by August on 4/26/20.
//

#ifndef LEETCODE_MAXIMUMSPLITTINGSCORE_H
#define LEETCODE_MAXIMUMSPLITTINGSCORE_H

/**
 * 5392. 分割字符串的最大得分
 * https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string/
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int sum = 0;
        int left = 0;
        vector<int> ans(s.size(), 0);
        for (auto &c: s) {
            if (c == '1') sum++;
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') left++;
            if (s[i] == '1') sum--;
            ans.push_back(left + sum);
        }
        return *max_element(ans.begin(), ans.end());
    }
};

#endif //LEETCODE_MAXIMUMSPLITTINGSCORE_H
