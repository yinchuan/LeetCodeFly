//
// Created by yinchuan on 1/12/23.
//

#ifndef LEETCODEFLY_LISTNODE_H
#define LEETCODEFLY_LISTNODE_H

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void print() const {
        cout << val << ", ";
        auto cursor = next;
        while(cursor != nullptr) {
            cout << cursor->val << ", ";
            cursor = cursor->next;
        }
        cout << endl;
    }
};
#endif //LEETCODEFLY_LISTNODE_H
