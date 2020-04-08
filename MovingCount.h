//
// Created by August on 4/8/20.
//

#ifndef LEETCODE_MOVINGCOUNT_H
#define LEETCODE_MOVINGCOUNT_H

/**
 * 面试题13. 机器人的运动范围
 * https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 */

#include <vector>

using namespace std;

class MovingCount {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        return dfs(0, 0, m, n, k, matrix);
    }

    int dfs(int x, int y, int m, int n, int k, vector<vector<int>> &matrix) {
        if (x < 0 || y < 0 || x == m || y == n || matrix[x][y] || sum(x) + sum(y) > k) return 0;
        matrix[x][y] = 1;
        return 1 + dfs(x-1,y,m,n,k,matrix) + dfs(x,y-1,m,n,k,matrix) + dfs(x+1,y,m,n,k,matrix) + dfs(x,y+1,m,n,k,matrix);
    }

    int sum(int n) {
        int a = n % 10;
        int b = (n - a) % 100 / 10;
        int c = n == 100 ? 1 : 0;
        return a + b + c;
    }
};

#endif //LEETCODE_MOVINGCOUNT_H
