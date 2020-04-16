//
// Created by August on 4/16/20.
//

#ifndef LEETCODE_MERGEINTERVALS_H
#define LEETCODE_MERGEINTERVALS_H

/**
 * 56. 合并区间
 * https://leetcode-cn.com/problems/merge-intervals/
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> res{};
        int a = intervals[0][0], b = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (b >= intervals[i][0]) {

                b = max(b, intervals[i][1]);
            }else  {
                res.push_back({a, b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
            if (i == intervals.size() - 1) {
                res.push_back({a, b});
            }
        }
        return res;
    }

    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
};

#endif //LEETCODE_MERGEINTERVALS_H
