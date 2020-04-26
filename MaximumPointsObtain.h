//
// Created by August on 4/26/20.
//

#ifndef LEETCODE_MAXIMUMPOINTSOBTAIN_H
#define LEETCODE_MAXIMUMPOINTSOBTAIN_H

/**
 * 5393. 可获得的最大点数
 * https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        for (int i = 0; i < k; ++i) {
            int temp = sum;
            temp -= cardPoints[k - i - 1];
            temp += cardPoints[cardPoints.size() - i - 1];
            if (temp > sum) sum = temp;
        }
        return sum;
    }
};

#endif //LEETCODE_MAXIMUMPOINTSOBTAIN_H
