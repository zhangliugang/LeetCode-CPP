//
// Created by August on 4/26/20.
//

#ifndef LEETCODE_LONGESTINCREASINGSUBSEQUENCE_H
#define LEETCODE_LONGESTINCREASINGSUBSEQUENCE_H

/**
 * 300. 最长上升子序列
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

#endif //LEETCODE_LONGESTINCREASINGSUBSEQUENCE_H
