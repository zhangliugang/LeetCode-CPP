//
// Created by August on 4/2/20.
//

#ifndef LEETCODE_SUDOKU_H
#define LEETCODE_SUDOKU_H

#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;

class Sudoku {
public:
    void solveSudoku(vector<vector<char>>& board) {
        map<string, int> map{};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    map[to_string(i * 10 + j)] = 9;
                }
            }
        }
    }

    vector<int> posiable(int x, int y) {
        vector<int> all{1, 2, 3, 4, 5, 6, 7, 8, 9};
        return  all;
    }
};

#endif //LEETCODE_SUDOKU_H
