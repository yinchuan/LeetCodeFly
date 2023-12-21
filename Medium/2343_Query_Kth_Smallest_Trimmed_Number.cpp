// https://leetcode.com/problems/query-kth-smallest-trimmed-number/
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
struct Trimmed {
    string s;
    int index;

    Trimmed(const string &s, int index) : s(s), index(index) {}

    bool operator<(const Trimmed &other) const {
        if (s == other.s) {
            return index < other.index;
        }

        return s < other.s;
    }
};

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        ios_base::sync_with_stdio(false);
        vector<int> ans;

        int n = nums[0].length();
        priority_queue<Trimmed> q;
        vector<int> buckets(10);

        for (const auto &query: queries) {
            int trim = query[1];
            int k = query[0];

            // init
            for(int i = 0; i < 10; i++) {
                buckets[i] = 0;
            }
            while (!q.empty()) {
                q.pop();
            }

            // split to buckets
            for(const auto &num: nums) {
                buckets[num[n-trim]-'0']++;
            }

            int key = 0;
            for(; key < 10 && k > buckets[key]; key++) {
                k -= buckets[key];
            }

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i][n-trim] != key+'0') continue;

                auto temp = Trimmed(nums[i].substr(n - trim, trim), i);
                if (q.size() < k) {
                    q.push(temp);
                    continue;
                }
                if (temp < q.top()) {
                    q.pop();
                    q.push(temp);
                }
            }
            ans.push_back(q.top().index);
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<int> ans;
    vector<string> nums;
    vector<vector<int>> queries;

    nums = {"102","473","251","814"}; queries = {{1,1},{2,3},{4,2},{1,2}}; //Output: {2,2,1,0}
    nums = {"24","37","96","04"}, queries = {{2,1},{2,2}}; // Output: {3,0}
    ans = sol.smallestTrimmedNumbers(nums, queries);
    print1D(ans);
}
        