// https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
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
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        ios_base::sync_with_stdio(false);

        // record index for quick lookup
        unordered_map<string, int> index1;
        index1.reserve(list1.size());
        for(int i = 0; i < list1.size(); i++) {
            index1[list1[i]] = i;
        }

        // record strings with the same sum of index
        unordered_map<int, vector<string>> sumIndex;
        int minSum = INT32_MAX;

        for(int i = 0; i < list2.size(); i++) {
            // not common
            if (!index1.contains(list2[i])) {
                continue;
            }

            // update minSum and save
            int sum = index1[list2[i]] + i;
            if (sum <= minSum) {
                minSum = sum;
                sumIndex[minSum].push_back(list2[i]);
            }
        }

        return sumIndex[minSum];
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<string> ans;
    vector<string> list1;
vector<string> list2;

    list1=;
list2;
    ans = sol.findRestaurant(list1, list2);
    std::cout << ans << std::endl;
}
        