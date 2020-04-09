//
// Created by August on 4/8/20.
//

#ifndef LEETCODE_COUNTANDSAY_H
#define LEETCODE_COUNTANDSAY_H

#include <string>

using namespace std;

class CountAndSay {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            s = nextString(s);
        }
        return s;
    }

    string nextString(string &s) {
        int i = 0, j = s.size();
        int n = 0;
        char t;
        string r;
        while (i < j) {
            t = s.at(i);
            n++;
            if (i + 1 == j || t != s[i + 1]) {
                r.append(to_string(n));
                r.append({t});
                n = 0;
            }
            i++;
        }
        return r;
    }
};

#endif //LEETCODE_COUNTANDSAY_H
