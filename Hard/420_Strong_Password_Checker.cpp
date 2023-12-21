// https://leetcode.com/problems/strong-password-checker/description/
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

using namespace std;

//#####
class Solution {
public:
    int strongPasswordChecker(string password) {
        bool found = false;
        int chars = 0;
        // check lower
        for (const char ch: password) {
            if (islower(ch)) {
                found = true;
                break;
            }
        }
        if (!found) chars++;

        // check upper
        found = false;
        for (const char ch: password) {
            if (isupper(ch)) {
                found = true;
                break;
            }
        }
        if (!found) chars++;

        // check digit
        found = false;
        for (const char ch: password) {
            if (isdigit(ch)) {
                found = true;
                break;
            }
        }
        if (!found) chars++;
        // those results give us 0-3 to chars spend on 
        // break triple, insert when too lack, replace when too extra

        // check size, this will decide how to break triples
        // both non-positive means size OK
        int lack = 6 - password.length();
        int extra = password.length() - 20;

        // fix triples
        int ans = 0;
        char lastlast, last;

        // size OK
        if (lack <= 0 && extra <= 0) { // size OK, just replace
            lastlast = password[0];
            last = password[1];
            for (int i = 2; i < password.length(); i++) {
                if (!(password[i] == last && password[i] == lastlast)) {
                    lastlast = last;
                    last = password[i];
                    continue; // not a triple
                }

                if (chars != 0) { // consume one from chars first, two birds in one stone
                    chars--;
                }
                ans++; // replace current char, either from chars, or any other char
                lastlast = '\0'; // can't use lastlast = last, last = [i], this will be picked up by next window
                last = '\0';
            }
        } else if (lack > 0) {
            lastlast = password[0];
            last = password[1];
            for (int i = 2; i < password.length(); i++) {
                if (!(password[i] == last && password[i] == lastlast)) {
                    lastlast = last;
                    last = password[i];
                    continue; // not a triple
                }
                // too lack, try insert from char
                if (chars != 0) { // insert one from chars
                    chars--;
                }
                ans++;
                lack--; // one less char lack after insert
                lastlast = '\0';
                last = password[i]; // could have the same char after current position
            }
        } else if (extra > 0) {
            lastlast = password[0];
            last = password[1];
            for (int i = 2; i < password.length(); i++) {
                // cut off extra chars from here, doesn't matter whay they are
                int left = password.length() - i;
                if (left <= extra) { // just delete the rest,  no need to replace
                    ans += extra;
                    extra = 0;
                    break;
                }

                if (!(password[i] == last && password[i] == lastlast)) {
                    lastlast = last;
                    last = password[i];
                    continue; // not a triple
                }

                // for aaaaa, if has enough extra, just delete
                if (i < (password.length() - 1) && password[i + 1] == password[i] && i < (password.length() - 2) &&
                    password[i + 2] == password[i]) {
                    if (extra >= 3) {
                        extra -= 3; // delete 3 to break aaaaa -> aa
                        ans += 3;
                        i += 2;
                        // lastlast and last keep the same
                    } else {
//                        replace current
                        ans++;
                        if (chars > 0) {
                            chars--;
                        }
                        lastlast = '\0';
                        last = '\0';
                    }
                    continue;
                }

                // for 0000a, replace 1, delete 2
                if (i < (password.length() - 1) && password[i + 1] == password[i]) {
                    if (extra >= 2) { // we can afford to delete 2
                        extra -= 2;
                        ans += 2;
                        i += 1;
                        lastlast = '\0';
                        last = '\0';
                    } else {
                        // do replace
                        ans++;
                        if (chars > 0) {
                            chars--;
                        }
                        lastlast = '\0';
                        last = '\0';

                    }
                    continue;
                }

                // 000a, better to delete, consume one from extra
                if (((i == password.length() - 1) || (password[i + 1] != password[i]))) {
                    if (extra >= 1) {
                        extra--; // delete
                        ans++;
                    } else {
                        if (chars > 0) {
                            chars--; // replace;
                        }
                        ans++;
                        lastlast = '\0';
                        last = '\0';
                    }
                    continue;
                }
            }

            // no next char, just delete
//            ans++;
//            extra--; // one less char extra after delete
        }

        // after fix triples
        // could be right size, still too lack, still too extra, still have chars left
        if (lack <= 0 && extra <= 0) { // right size
            // just replace whatever left in chars
            return ans + chars;
        }

        if (lack > 0) { // still too lack
            // insert chars, then replace, if lack <= chars
            // or insert chars, then insert others, if lack > chars
            ans += max(chars, lack);
            return ans;
        }

        if (extra > 0) { // still too extra
            return ans + chars + extra;
        }

        return -1; // shouldn't run to here
    }

};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string password;

//    password = "a"; // 5
//    password = "aA1"; // 3
//    password = "1337C0d3"; // 0
//    password = "aaaaa"; // 2
//    password = "aaaaaaaaaaaaaaaaaaaaaaa"; // 9
    password = "aaaaaaaaa1Aaa1aaaaaaaaaaaa"; // 10
//    password = "aaaaaaaaa11aa1aaaaaaaaaaaa"; // 10
//    password = "aaaaaaaaa1Aaa1" ; // 3
//    password = "aaaaaaaaaaaa" ; // 4
//    password = "aaaabbbbccccddeeddeeddeedd"; // 8
    password = "aaaaAAAAAA000000123456"; // 5
    ans = sol.strongPasswordChecker(password);
    std::cout << ans << std::endl;
}
        