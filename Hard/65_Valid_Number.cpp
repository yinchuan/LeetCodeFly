// https://leetcode.com/problems/valid-number/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

//#####
class Solution {
private:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

public:
    bool isNumber(string s) {
        enum states {
            START, FIRST_SIGN, INTEGER_PART, DOT, FRACTION_PART, E, SECOND_SIGN, INTEGER, FALSE
        };

        if (s.back() == 'e' || s.back() == 'E' || s == ".") return false;
        enum states state = START;
        int dotIndex;
        for (int i = 0; i < s.length(); i++) {
            switch (state) {
                case START:
                    if (isDigit(s[i])) {
                        state = INTEGER_PART;
                        break;
                    }
                    if (s[i] == '+' || s[i] == '-') {
                        state = FIRST_SIGN;
                        break;
                    }
                    if (s[i] == '.') {
                        dotIndex = i;
                        state = DOT;
                        break;
                    }
                    state = FALSE;
                    break;
                case FIRST_SIGN:
                    if (isDigit(s[i])) {
                        state = INTEGER_PART;
                        break;
                    }
                    if (s[i] == '.') {
                        dotIndex = i;
                        state = DOT;
                        break;
                    }
                    state = FALSE;
                    break;
                case INTEGER_PART:
                    if (s[i] == '.') {
                        dotIndex = i;
                        state = DOT;
                        break;
                    }
                    if (isDigit(s[i])) { break; }
                    if (s[i] == 'e' || s[i] == 'E') {
                        state = E;
                        break;
                    }
                    state = FALSE;
                    break;
                case DOT:
                    if (isDigit(s[i])) {
                        state = FRACTION_PART;
                        break;
                    }
                    if (s[i] == 'e' || s[i] == 'E') {
                        state = E;
                        break;
                    }
                    state = FALSE;
                    break;
                case FRACTION_PART:
                    if (isDigit(s[i])) { break; }
                    if (s[i] == 'e' || s[i] == 'E') {
                        state = E;
                        break;
                    }
                    state = FALSE;
                    break;
                case E:
                    if (s[i] == '+' || s[i] == '-') {
                        state = SECOND_SIGN;
                        break;
                    }
                    if (isDigit(s[i])) {
                        state = INTEGER;
                        break;
                    }
                    state = FALSE;
                    break;
                case SECOND_SIGN:
                    if (isDigit(s[i])) {
                        state = INTEGER;
                        break;
                    }
                    state = FALSE;
                    break;
                case INTEGER:
                    if (isDigit(s[i])) {
                        break;
                    }
                    state = FALSE;
                    break;
                case FALSE:
                default:
                    return false;
            }
        }


        // when finish
        switch (state) {
            case START:
            case FIRST_SIGN:
            case E:
            case SECOND_SIGN:
            case FALSE:
                return false;
            case DOT:
                // must have a digit before '.'
                return isDigit(s[dotIndex-1]);
            case INTEGER_PART:
            case FRACTION_PART:
            case INTEGER:
                // check before and after dot
                // if found a dot, then must have a char after dot
                if (dotIndex >= 0 && dotIndex < s.length()) {
                    if (isDigit(s[dotIndex+1])) {
                        return true;
                    }
                    if (dotIndex-1 < 0 || !isDigit(s[dotIndex-1])) {
                        return false;
                    }
                }
                return true;
            default:
                cout << "un handled state: " << state << endl;
                return false;
        }
        return true;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<string> goods{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93",
                         "-123.456e789"};
    vector<string> bads{"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "..", ".e1", "4e+", "+.", "+E3"};
    cout << "True: " << endl;
    for (const auto &s: goods) {
        cout << sol.isNumber(s);
    }
    cout << endl;
    cout << "False: " << endl;
    for (const auto &s: bads) {
        cout << sol.isNumber(s);
    }
}
        