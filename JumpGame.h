//
// Created by August on 4/17/20.
//

#ifndef LEETCODE_JUMPGAME_H
#define LEETCODE_JUMPGAME_H

/**
 * 55. 跳跃游戏
 * https://leetcode-cn.com/problems/jump-game/
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        for (int i = nums.size() - 2; i >= 0; ) {
            if (nums[i] == 0) {
                int j = i - 1;
                while (j >= 0) {
                    if (nums[j] > i - j) {
                        i = j;
                        break;
                    }
                    j--;
                }
                if (i == j) continue;
                return false;
            }
            i--;
        }
        return true;
    }
};

#endif //LEETCODE_JUMPGAME_H
