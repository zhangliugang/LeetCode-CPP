//
// Created by August on 4/10/20.
//

#ifndef LEETCODE_REVERSEWORDS_H
#define LEETCODE_REVERSEWORDS_H

/**
 * 151. 翻转字符串里的单词
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/
 */

#include <string>
#include <vector>

using namespace std;

class ReverseWords {
public:
    string reverseWords(string s) {
        int j = 0, k = 0;
        vector<string> l{};
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) != ' ') {
                j++;
                if (i == s.size() - 1) {
                    l.push_back(s.substr(k, j));
                }
            } else {
                if (j != 0) {
                    l.push_back(s.substr(k, j));
                    k = i;
                }
                k++;
                j = 0;
            }
        }
        l.reserve(1);
        string ss{};
        for (int i = l.size() - 1; i >= 0; --i) {
            ss.append(l[i]);
                ss.append(" ");
        }
         ss.pop_back();
        return ss;
    }
};

#endif //LEETCODE_REVERSEWORDS_H
