// https://leetcode.com/problems/shuffle-string/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#####
using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       auto ans = string(s.length(), ' ');
       for(int i = 0; i < s.length(); i++) {
           ans[indices[i]] = s[i];
       }

       return ans;
    }
};
//#####

//===== do not copy lines after this to LeetCode
int main() {
    Solution s;
    string ans;
    string input_s;
    vector<int> input_indices;

    input_s = "codeleet";
    input_indices = {4,5,6,7,0,2,1,3};;
    ans = s.restoreString(input_s, input_indices);
    std::cout << ans << std::endl;

    input_s = "abc";
    input_indices = {0,1,2};;
    ans = s.restoreString(input_s, input_indices);
    std::cout << ans << std::endl;
}
