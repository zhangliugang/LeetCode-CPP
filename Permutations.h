//
// Created by August on 4/25/20.
//

#ifndef LEETCODE_PERMUTATIONS_H
#define LEETCODE_PERMUTATIONS_H

/**
 * 46. 全排列
 * https://leetcode-cn.com/problems/permutations/
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> visited(nums.size(), 0);
        backTrack(ans, nums, visited, tmp);
        return ans;
    }

    void backTrack(vector<vector<int>> &ans, vector<int> &nums, vector<bool> &visited, vector<int> tmp) {
        if (tmp.size() == nums.size()) {
            vector<int> newv;
            newv.swap(tmp);
            ans.push_back(newv);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            tmp.push_back(nums[i]);
            backTrack(ans, nums, visited, tmp);
            visited[i] = false;
            tmp.pop_back();
        }
    }
};

#endif //LEETCODE_PERMUTATIONS_H
