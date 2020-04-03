//
// Created by August on 4/2/20.
//

#ifndef LEETCODE_ZIGZAG_H
#define LEETCODE_ZIGZAG_H

/**
 * 6. Z 字形变换
 * https://leetcode-cn.com/problems/zigzag-conversion/
 */

#include <string>
#include <vector>
/**
A    B
I   KL
C  D E
F G  H
IJ   K
*/

using namespace std;

class ZigZag {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 1) return s;
        int slice_size = numRows * 2 - 2;
        vector<string> slices = {};
        string res;
        for (int i = 0; i < s.size() / slice_size + 1; ++i) {
            slices.push_back(s.substr(i * slice_size, slice_size));
        }

        for (int i = 0; i < numRows; ++i) {
            for (string & ss: slices) {
                if (i >= ss.size()) continue;
                res.push_back(ss[i]);
                if (i != 0 && i != numRows - 1) {
                    int j = slice_size - i;
                    if (j < ss.size()) {
                        res.push_back(ss[j]);
                    }
                }
            }
        }
        return res;
    }
};

#endif //LEETCODE_ZIGZAG_H
