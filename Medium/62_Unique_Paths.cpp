// https://leetcode.com/problems/unique-paths/?envType=daily-question&envId=2023-11-30
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <numeric>
using namespace std;
//#####
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n==1) return 1;

        // binomial
        vector<int> counter(n-1, 1); // store a row without the first col(because it's value is 1)

        for(int i = 1; i < m; i++) {
            counter[0] += 1;
            for(int j = 1; j < counter.size(); j++) { // add left to right
                counter[j] += counter[j-1];
            }
        }

        return counter.back();
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int m = 2;
    int n = 1;

    ans = sol.uniquePaths(m, n);
    std::cout << ans << std::endl;
}
        