//
// Created by August on 4/24/20.
//

#ifndef LEETCODE_REVERSEPAIRS_H
#define LEETCODE_REVERSEPAIRS_H

/**
 * 面试题51. 数组中的逆序对
 * https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }

    int dfs(vector<int> &nums, int m, int n) {
        if (m + 1 >= n) return 0;
        int mid = (m + n) / 2;
        int res = dfs(nums, m, mid) + dfs(nums, mid, n);
        sort(nums.begin() + m, nums.begin() + mid);
        for (int i = mid; i < n; ++i) {
            res += nums.begin() + mid - std::upper_bound(nums.begin() + m, nums.begin() + mid, nums[i]);
        }
        return res;
    }
};

#endif //LEETCODE_REVERSEPAIRS_H
