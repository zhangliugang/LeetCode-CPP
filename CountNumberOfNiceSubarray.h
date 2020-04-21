//
// Created by August on 4/21/20.
//

#ifndef LEETCODE_COUNTNUMBEROFNICESUBARRAY_H
#define LEETCODE_COUNTNUMBEROFNICESUBARRAY_H

/**
 * 1248. 统计「优美子数组」
 * https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odds{};
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) {
                odds.push_back(i);
            }
        }
        if (odds.size() < k) return 0;
        for (int j = 0; j <= odds.size() - k; ++j) {
            int before = j == 0 ? odds[j] + 1 : odds[j] - odds[j - 1];
            int after = j + k == odds.size() ? nums.size() - odds[j + k - 1]: odds[j + k] - odds[j + k - 1];
            ans += before * after;
        }
        return  ans;
    }
};

#endif //LEETCODE_COUNTNUMBEROFNICESUBARRAY_H
