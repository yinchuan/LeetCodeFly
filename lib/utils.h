//
// Created by yinchuan on 1/12/23.
//

#ifndef LEETCODEFLY_UTILS_H
#define LEETCODEFLY_UTILS_H

using namespace std;

template <class T>
void print1D(const vector<T> &v) {
    for (const auto entry: v) {
        cout << entry << ", ";
    }
    cout << endl;
}

template <class T>
void print2D(const vector<vector<T>> &twoD) {
    for(const auto &v: twoD) {
        print1D(v);
    }
}

#endif //LEETCODEFLY_UTILS_H
