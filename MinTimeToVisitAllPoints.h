//
// Created by August on 4/21/20.
//

#ifndef LEETCODE_MINTIMETOVISITALLPOINTS_H
#define LEETCODE_MINTIMETOVISITALLPOINTS_H

/**
 * 1266. 访问所有点的最小时间
 * https://leetcode-cn.com/problems/minimum-time-visiting-all-points/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size() - 1;) {
            auto a = points[i];
            auto b = points[++i];
            ans += max(abs(a[0] - b[0]), abs(a[1] - b[1]));
        }
        return ans;
    }
};

#endif //LEETCODE_MINTIMETOVISITALLPOINTS_H
