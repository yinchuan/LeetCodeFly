//
// Created by yinchuan on 1/12/23.
//

#ifndef LEETCODEFLY_UTILS_H
#define LEETCODEFLY_UTILS_H

using namespace std;

void print1D(const vector<int> &v) {
    for (const auto entry: v) {
        cout << entry << ", ";
    }
    cout << endl;
}

void print2D(const vector<vector<int>> &twoD) {
    for(const auto &v: twoD) {
        print1D(v);
    }
}

#endif //LEETCODEFLY_UTILS_H
