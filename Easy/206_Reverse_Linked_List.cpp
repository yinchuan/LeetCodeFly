// https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *end = nullptr;
        return reverse(head, end);
    }

    ListNode* reverse(ListNode *head, ListNode *&end) {
        if (head == nullptr || head->next == nullptr) {
            end = head;
            return head;
        }

        auto newHead = reverse(head->next, end);
        if (end != nullptr) (end)->next = head;
        end = head;
        (end)->next = nullptr;
        return newHead;
    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    ListNode* ans;
    ListNode* head;

    vector<int> data ={1,2,3,4,5};
    ListNode *end;
    head = new ListNode(data[0]);
    end = head;
    for (int i = 1; i < data.size(); i++) {
        auto temp = new ListNode(data[i]);
        end->next = temp;
        end = temp;
    }
    head->print();
    ans = sol.reverseList(head);
    ans->print();
}
        