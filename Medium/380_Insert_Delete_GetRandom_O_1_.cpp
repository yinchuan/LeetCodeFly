// https://leetcode.com/problems/insert-delete-getrandom-o1/
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
#include <cmath>
#include "../lib/ListNode.h"
#include "../lib/TreeNode.h"
#include "../lib/utils.h"

using namespace std;

//#####
class RandomizedSet {
private:
    struct Node {
        int key;
        Node *next;

        Node(int key) : key(key) {}

        Node(int key, Node *next = nullptr) : key(key), next(next) {}

        Node() {};
    };

    static int hash(int key) {
        return abs(key % size);
    }

    const static int size = 1063;
    Node **buckets;
    int *counts;
    int total = 0;

public:
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        buckets = new Node *[size]{nullptr};
        counts = new int[size]{0};
        srand(time(0)); // not good
    }

    bool insert(int val) {
        bool exist = contains(val);
        if (exist) {
            return false;
        }

        auto index = hash(val);
        auto temp = new Node(val, buckets[index]);
        buckets[index] = temp;
        counts[index]++;
        total++;
        return true;
    }

    bool remove(int val) {
        auto index = hash(val);
        Node *cursor = buckets[index];
        Node *pre = nullptr;
        while(cursor != nullptr) {
            if (cursor->key == val) {
                break;
            }
            pre = cursor;
            cursor = cursor->next;
        }
        // if not found
        if (cursor == nullptr) return false;

        // if head
        if (pre == nullptr) {
            buckets[index] = cursor->next;
            delete cursor;
        } else {
            pre->next = cursor->next;
            delete cursor;
        }

        counts[index]--;
        total--;
        return true;
    }

    int getRandom() {
        int n = rand() % total + 1;

        // locate bucket
        int i = 0;
        for (; i < size && counts[i] < n; i++) {
            n -= counts[i];
        }

        auto cursor = buckets[i];
        while (n > 1) {
            cursor = cursor->next;
            n--;
        }

        return cursor->key;
    }

    bool contains(int val) {
        Node *cursor = buckets[hash(val)];
        while (cursor != nullptr) {
            if (cursor->key == val) {
                return true;
            }
            cursor = cursor->next;
        }
        return false;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    int val;

    val;
    ans = sol.insert(val);
    std::cout << ans << std::endl;
}
        