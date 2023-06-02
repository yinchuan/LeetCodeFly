// https://leetcode.com/problems/sorting-the-sentence/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#####
using namespace std;
class Solution {
public:
    string sortSentence(string s) {
        int indices[9][2]; // store start loc and length of each word
        int loc, start=0, count = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                loc = s[i - 1] - '0' - 1;
                indices[loc][0] = start;
                indices[loc][1] = i - 1 - start; // length of the word
                count++;
                start = i+1;
            }
        }
        loc = s[s.length() - 1] - '0' - 1;
        indices[loc][0] = start;
        indices[loc][1] = s.length() - 1 - start;
        count++;

        string ans;
        for (int i = 0; i < count-1; i++) {
            ans += s.substr(indices[i][0], indices[i][1]);
            ans += ' ';
        }
        ans += s.substr(indices[count-1][0], indices[count-1][1]);

        return ans;
    }
};
//#####

//===== do not copy lines after this to LeetCode
int main() {
    Solution s;
    string ans, input;

    input = "is2 sentence4 This1 a3";
    cout << "input: " << input << endl;
    ans = s.sortSentence(input);
    std::cout << ans << std::endl;

    string s1 = "Myself2 Me1 I4 and3";
    cout << "input: " << s1 << endl;
    ans = s.sortSentence(s1);
    std::cout << ans << std::endl;
}
