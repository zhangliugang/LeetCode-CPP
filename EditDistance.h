//
// Created by August on 4/6/20.
//

#ifndef LEETCODE_EDITDISTANCE_H
#define LEETCODE_EDITDISTANCE_H

/**
 * 72. 编辑距离
 * https://leetcode-cn.com/problems/edit-distance/
 */

#include <string>
#include <vector>
#include <array>

using namespace std;

class EditDistance {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.size(), len2 = word2.size();
        int dp[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[len1][len2];
    }
};

#endif //LEETCODE_EDITDISTANCE_H
