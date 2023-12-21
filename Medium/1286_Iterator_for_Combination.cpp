// https://leetcode.com/problems/iterator-for-combination/
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
class CombinationIterator {
private:
    string chars;
    int n, k;

    int leading, current, nextBit, slots;
    int progress;
    int limit;

    int getBit(int n, int i) {
        return (n >> i) & 1;
    }

public:
    void printProgress() {
        for (int i = n - 1; i >= 0; i--) {
            cout << getBit(progress, i);
        }
        cout << endl;
    }

    CombinationIterator(string characters, int combinationLength) : chars(characters), k(combinationLength) {
        n = chars.length();
        limit = ((1 << (n-k)) - 1) << k;
    }

    string next() {
        if (progress == 0) {
            progress = (1 << (n - k )) - 1;
            leading = n - k - 1;
            slots = 0;
            current = leading;
            nextBit = current - 1;
        } else {
            if (current == leading) { // move leading left
                leading++;
                progress = (1 << leading) + (1 << (n - k - 1)) - 1; // reset for current round
                slots++;
                current = nextBit;
                nextBit--;
            } else {
                progress += (1 << current); // move to left for 1 bit
                current++;
                if (current - nextBit - 1 >= slots) {
                    current = nextBit;
                    nextBit = current - 1;
                    if (current == -1) {
                        current = leading;
                        nextBit = n - k - 2;
                    }
                }
            }
        }

        // build string
        string s;
        for (int i = n - 1, j = 0; i >= 0; i--, j++) {
            if (getBit(progress, i) == 0) {
                s += chars[j];
            }
        }
        return s;
    }

    bool hasNext() {
        return progress <= limit;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//#####

// do not copy lines after this to LeetCode
int main() {
    string characters = "abcde";
    int combinationLength = 2;
    CombinationIterator *obj = new CombinationIterator(characters, combinationLength);
//    obj->next();
//    obj->printProgress();
//    obj->next();
//    obj->printProgress();
//    obj->next();
//    obj->printProgress();
//    obj->next();
//    obj->printProgress();
//    obj->next();
//    obj->printProgress();
//    obj->next();
//    obj->printProgress();
    for (int i = 0; i < 20; i++) {
        if (!obj->hasNext()) break;
        cout << (i+1) << ": " << obj->next() << endl;
        obj->printProgress();
    }
}
        