// https://leetcode.com/problems/design-hashset/
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
#include "../lib/utils.h"
using namespace std;
//#####
struct Node {
    int key;
    Node *next;
    Node (int key): key(key) {}
    Node() {}
};
class MyHashSet {
private:
    Node **buckets;

    int hash(int key) {
        return key % 10000;
    }
public:
    MyHashSet() {
        ios_base::sync_with_stdio(false);
        buckets = new Node*[10000]{nullptr}; // each bucket has at most 100 pairs
    }

    ~MyHashSet() {
        for(int i = 0; i < 10000; i++) {
            auto cursor = buckets[i];
            Node *pre;
            while(cursor != nullptr) {
                pre = cursor;
                cursor = cursor->next;
                delete pre;
            }
        }
        delete[] buckets;
    }
    
    void add(int key) {
        if (contains(key)) return;

        auto index = hash(key);
        Node *head = buckets[index];
        auto temp = new Node(key);
        temp->next = head;
        buckets[index] = temp;
    }
    
    void remove(int key) {
        auto index = hash(key);
        Node *cursor = buckets[index];
        Node *pre = nullptr;
        while(cursor != nullptr) {
            if (cursor->key == key) {
                break;
            }
            pre = cursor;
            cursor = cursor->next;
        }
        // if not found
        if (cursor == nullptr) return;

        // if head
        if (pre == nullptr) {
            buckets[index] = cursor->next;
            delete cursor;
        } else {
            pre->next = cursor->next;
            delete cursor;
        }
    }
    
    bool contains(int key) {
        Node *cursor = buckets[hash(key)];
        while (cursor != nullptr) {
            if (cursor->key == key) {
                return true;
            }
            cursor = cursor->next;
        }
        return false;
    }


};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    void ans;
    int key;

    key;
    ans = sol.add(key);
    std::cout << ans << std::endl;
}
        