//
// Created by August on 4/2/20.
//

#ifndef LEETCODE_GAMEOFLIFE_H
#define LEETCODE_GAMEOFLIFE_H

#include <iostream>
#include <vector>

/**
 * 289. 生命游戏
 * https://leetcode-cn.com/problems/game-of-life/
 */

using namespace std;
class GameOfLife {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};

        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        continue;
                    }
                    if ((board[x][y] & 0b01) > 0)
                        count++;
                }
                if (board[i][j] > 0) {
                    if (count == 2 || count == 3) {
                        board[i][j] = 0b11;
                    }
                } else {
                    if (count == 3) {
                        board[i][j] = 0b10;
                    }
                }
            }

        }

        for (vector<int> &i : board) {
            for (int &j : i) {
                j >>= 1;
            }
        }
    }
};

#endif //LEETCODE_GAMEOFLIFE_H
