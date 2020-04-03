//
// Created by August on 4/2/20.
//

#ifndef LEETCODE_SETMATRIXZERO_H
#define LEETCODE_SETMATRIXZERO_H

/**
 * 73. 矩阵置零
 * https://leetcode-cn.com/problems/set-matrix-zeroes/
 */

#include <vector>
#include <unordered_set>

using namespace std;

class SetMatrixZero {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> x = {}, y = {};
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    x.insert(i);
                    y.insert(j);
                }
            }
        }

        unordered_set<int>::iterator it;
        for (it = x.begin();it != x.end();it++) {
            for (int i = 0; i < m; ++i) {
                matrix[*it][i] = 0;
            }
        }
        for (it = y.begin(); it != y.end(); it++) {
            for (int i = 0; i < n; ++i) {
                matrix[i][*it] = 0;
            }
        }
    }
};

#endif //LEETCODE_SETMATRIXZERO_H
