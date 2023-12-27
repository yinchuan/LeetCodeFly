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
class Solution {
private:
    vector<string> countingSort(const vector<string> &input, int position) {
       vector<int> counts(10); // only digits

       for(const auto &s: input) {
           counts[s[position]-'0']++;
       }

       // calculate start index
       int start = 0;
       for(int i = 0; i < 10; i++) {
           int count = counts[i];
           counts[i] = start;
           start += count;
       }

       // put elements to right place
       vector<string> ret(input.size());
       for(const auto &s: input) {
           int key = s[position]-'0';
           ret[counts[key]] = s;
           counts[key]++;
       }

       return ret;
    }

    vector<string> radixSort(const vector<string> &input, int last) {
        vector<string> temp = input;
        for(int i = temp[0].length()-1; i >= last; i--) {
            temp = countingSort(temp, i);
        }

        return temp;
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        ios_base::sync_with_stdio(false);
        vector<int> ans;
        int n = nums.size();

        for(const auto &query: queries) {
            int trim = query[1];
            int k = query[0];

            auto sorted = radixSort(nums, nums[0].length()-trim);
            for(int i = 0; i < n; i++) {
                if (nums[i] == sorted[k-1]) {
                    ans.emplace_back(i);
                    break;
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
    vector<int> ans;
    vector<string> nums;
    vector<vector<int>> queries;

    nums = {"102", "473", "251", "814"}; queries = {{1, 1}, {2, 3}, {4, 2}, {1, 2}}; //Output: {2,2,1,0}
//    nums = {"24", "37", "96", "04"}, queries = {{2, 1}, {2, 2}}; // Output: {3,0}
    ans = sol.smallestTrimmedNumbers(nums, queries);
    print1D(ans);
}
        