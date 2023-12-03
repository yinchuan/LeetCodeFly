// https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2023-11-30
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <queue>

#include "../lib/ListNode.h"
#include "../lib/utils.h"

using namespace std;
//#####
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> ans(k, nullptr); // prepare space for return, use k-1 elements first

        /* 1 one pass
        int counter = 0;
        auto temp = head;

        for(; counter < ans.size() && temp != nullptr; counter++, temp = temp->next) {
            ans[counter] = temp;
        }

        if (temp == nullptr) {
            for (int i = 0;
                 i < counter - 1; i++) { // only need to break counter-1 elements, the last one already points to next
                ans[i]->next = nullptr;
            }
            return ans;
        }

        // have elements left
        while (temp != nullptr) {
            // moving pointer
            for (int i = counter % k; i < k - 1; i++) {
                ans[i] = ans[i]->next;
            }
            counter++;
            temp = temp->next;
        }
        for (int i = k - 1; i >= 1; i--) {
            ans[i] = ans[i - 1]->next;
            ans[i - 1]->next = nullptr;
        }
        ans[0] = head;
        */

        // 2 count then split
        int count = 0;
        auto cursor = head;
        ListNode *end = nullptr;
        while (cursor != nullptr) {
            count++;
            cursor = cursor->next;
        }

        int size = max(count / k, 1);
        int bigger = count % k;
        int biggerSize = count / k + 1;
        int parts = min(count, k);
        cursor = head;
        ans[0] = head;
        for (int i = 1; i <= bigger; i++) {
            count = 0;
            while (cursor != nullptr) {
                count++;
                // found the end of a part
                if (count == biggerSize) {
                    end = cursor;
                    cursor = cursor->next;
                    ans[i] = cursor;
                    end->next = nullptr;
                    break;
                } else {
                    cursor = cursor->next;
                }
            }
        }
        for (int i = bigger+1; i < parts; i++) {
            count = 0;
            while (cursor != nullptr) {
                count++;
                // found the end of a part
                if (bigger && count == size) {
                    end = cursor;
                    cursor = cursor->next;
                    ans[i] = cursor;
                    end->next = nullptr;
                    break;
                } else {
                    cursor = cursor->next;
                }
            }
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    ListNode *head = nullptr, *temp;
    int k;

    vector<int> headElements = {1,2,3}; k = 5;
//    vector<int> headElements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; k = 3;
    for (int i = headElements.size() - 1; i >= 0; i--) {
        head = new ListNode(headElements[i], head);
    }

    auto ans = sol.splitListToParts(head, k);
    for (const auto &head: ans) {
        if (head != nullptr) {
            head->print();
        } else {
            cout << "null" << endl;
        }
    }

    queue<int> q;

}
        