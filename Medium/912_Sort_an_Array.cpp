// https://leetcode.com/problems/sort-an-array/
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
public:
    vector<int> sortArray(vector<int> &nums) {
//        merge_sort_topdown_recursion(nums, 0, nums.size() - 1);
//        merge_sort_bottom_up_iteration(nums);
//        bubble(nums);
        insertion(nums);
        return nums;
    }

    void insertion(vector<int> &nums) {
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i; j >= 1 && nums[j] < nums[j-1]; j--) {
                swap(nums[j], nums[j-1]);
            }
        }
    }

    void bubble(vector<int> &nums) {
        bool swapped = true;
        int n = nums.size() - 1;
        int newN;

        while(swapped) {
            swapped = false;
            for(int i = 0; i < n; i++) {
                if (nums[i] > nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                    swapped = true;
                    newN = i;
                }
            }
            n = newN;
        }
    }
    void merge_sort_bottom_up_iteration(vector<int> &nums) {
        if (nums.size() == 1) return;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                swap(nums[0], nums[1]);
            }
            return;
        }
        int size = 2;

        vector<int> holder(nums.size());
        while (size/2 < nums.size()) {
            for (int start = 0; start < nums.size(); start += size) {
                if ((nums.size() - start) < size / 2) { // less than 1 block
                    while(start < nums.size()) {
                        holder[start] = nums[start];
                        start++;
                    }
                    break; // last element, no merge
                }

                int firstHalf = start;
                int firstEnd = start + size / 2; // non-inclusive
                int secondHalf = start + size / 2;
                int secondEnd = min((int) nums.size(), start + size);

                int writer = start;
                while (firstHalf < firstEnd && secondHalf < secondEnd) {
                    if (nums[firstHalf] < nums[secondHalf]) {
                        holder[writer] = nums[firstHalf];
                        firstHalf++;
                        writer++;
                    } else {
                        holder[writer] = nums[secondHalf];
                        secondHalf++;
                        writer++;
                    }
                }
                while (firstHalf < firstEnd) {
                    holder[writer] = nums[firstHalf];
                    writer++;
                    firstHalf++;
                }
                while (secondHalf < secondEnd) {
                    holder[writer] = nums[secondHalf];
                    writer++;
                    secondHalf++;
                }
            }

            for(int i = 0; i < nums.size(); i ++) {
                nums[i] = holder[i];
                holder[i] = 0;
            }
            size *= 2;
        }
    }

    void merge_sort_topdown_recursion(vector<int> &nums, int start, int end) {
        if (start == end) return; // one element

        if ((end - start) == 1) { // two elements
            if (nums[start] > nums[end]) {
                swap(nums[start], nums[end]);
            }
            return;
        }

        // sub
        int middle = start + (end - start) / 2;
        merge_sort_topdown_recursion(nums, start, middle);
        merge_sort_topdown_recursion(nums, middle + 1, end);

        // merge
        vector<int> merged(end - start + 1);
        int i, j, k;
        for (i = start, j = middle + 1, k = 0; i <= middle && j <= end; k++) {
            if (nums[i] <= nums[j]) {
                merged[k] = nums[i];
                i++;
            } else {
                merged[k] = nums[j];
                j++;
            }
        }
        while (i <= middle) {
            merged[k] = nums[i];
            i++;
            k++;
        }
        while (j <= end) {
            merged[k] = nums[j];
            j++;
            k++;
        }
        for (i = 0; i < merged.size(); i++) {
            nums[start + i] = merged[i];
        }
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<int> ans;
    vector<int> nums;

    nums = {5, 2, 3, 1, 6, 6, 2, 1, 1, 1};
    ans = sol.sortArray(nums);
    print1D(ans);
}
        