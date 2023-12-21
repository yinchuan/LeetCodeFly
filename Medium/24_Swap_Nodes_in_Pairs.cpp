// https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
#include "../lib/TreeNode.h"
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
    ListNode* swapPairs(ListNode* head) {
        ios_base::sync_with_stdio(false);

        // 1. recurssion
        // if (head == nullptr) return nullptr;
        // if (head->next == nullptr) return head;

        // auto temp = head->next;
        // head->next = swapPairs(head->next->next);
        // temp->next = head;

        // return temp;

        // 2. iteration
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode *cursor, *nn, *prev, *temp;

        // swap first two
        cursor = head;
        nn = cursor->next->next;
        temp = head->next;
        temp->next = head;
        prev = head;
        head = temp;
        cursor = nn;

        while(cursor != nullptr && cursor->next != nullptr) {
            nn = cursor->next->next;
            temp = cursor->next;
            temp->next = cursor;
            prev->next = temp;
            prev = cursor;
            cursor = nn;
        }
        prev->next = cursor;
        return head;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    ListNode* ans;
    ListNode* head;

    head;
    ans = sol.swapPairs(head);
    std::cout << ans << std::endl;
}
        