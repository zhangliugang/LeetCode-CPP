//
// Created by August on 4/26/20.
//

#ifndef LEETCODE_DIAGONALTRAVERSE2_H
#define LEETCODE_DIAGONALTRAVERSE2_H

/**
 * 5394. 对角线遍历 II
 * https://leetcode-cn.com/problems/diagonal-traverse-ii/
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans{};
        vector<vector<int>> sum{};
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                sum.push_back({i + j, j, nums[i][j]});
            }
        }
        sort(sum.begin(), sum.end());
        for (auto &n: sum) {
            ans.push_back(n[2]);
        }
        return ans;
    }
};

#endif //LEETCODE_DIAGONALTRAVERSE2_H
