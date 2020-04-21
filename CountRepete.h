//
// Created by August on 4/19/20.
//

#ifndef LEETCODE_COUNTREPETE_H
#define LEETCODE_COUNTREPETE_H

/**
 * 466. 统计重复个数
 * https://leetcode-cn.com/problems/count-the-repetitions/
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0 || n2 == 0) return 0;
        int len1 = s1.size(), len2 = s2.size();
        unordered_map<int, pair<int, int>> map{};
        int c1 = 0, c2 = 0;
        int j = 0;
        while (c1 < n1) {
            for (int i = 0; i < len1; ++i) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        c2 ++;
                    }
                }
            }
            c1++;
            if (map.end() != map.find(j)) {
                auto p = map[j];
                int cc1 = c1 - p.first;
                int cc2 = c2 - p.second;
                c2 += cc2 * ((n1 - c1) / cc1);
                c1 = c1 + ((n1 - c1) / cc1) * cc1;
            } else {
                map[j] = {c1, c2};
            }
        }
        return c2 / n2;
    }
};

#endif //LEETCODE_COUNTREPETE_H
