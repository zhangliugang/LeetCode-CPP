//
// Created by August on 4/4/20.
//

#ifndef LEETCODE_TRAPPINGRAINWATER_H
#define LEETCODE_TRAPPINGRAINWATER_H

/**
 * 42. 接雨水
 * https://leetcode-cn.com/problems/trapping-rain-water/
 */

#include <vector>
#include <iostream>

using namespace std;

class Trapping {
public:
    int trap(vector<int>& height) {
        auto idx = maxidx(height, 0, height.size());
        return trap(idx, height, 0, idx) + trap(idx, height, idx + 1, height.size());
    }

    int trap(int it, vector<int>& height, int start, int end) {
        if (end - start <= 1) return 0;
        int max = maxidx(height, start, end);
        int c = 0, res = 0, w = 0;

        if (max < it) {
            w = it - max - 1;
            for (int i = max + 1; i < it; ++i) {
                c += height[i];
            }
            res += trap(max, height, 0, max);
        } else {
            w = max - it - 1;
            for (int i = it + 1; i < max; ++i) {
                c += height[i];
            }
            res += trap(max, height, max + 1, end);
        }
        res += w * min(height[it], height[max]) - c;
        return res;
    }

    int maxidx(vector<int> &v, int start, int end) {
        int idx = 0, value = 0;
        for (int i = start; i < end ; ++i) {
            if (v[i] >= value) {
                value = v[i];
                idx = i;
            }
        }
        return idx;
    }
};

#endif //LEETCODE_TRAPPINGRAINWATER_H
