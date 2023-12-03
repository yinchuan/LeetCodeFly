// https://leetcode.com/problems/search-suggestions-system/
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
class Trie {
private:
    char key;
    bool isEnd = false;
    vector<Trie*> children;

    void doPrint(string &s) {
        if (key != '\0') s.push_back(key);
        if (isEnd) {
            cout << s << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (children[i] == nullptr) continue;
            children[i]->doPrint(s);
        }
        if (key != '\0') s.pop_back();
    }

public:
    Trie(char key) : key(key) {
        children.reserve(26);
    }

    void setEnd() {
        isEnd = true;
    }

    void insert(const string &s) {
        auto temp = this;
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (temp->children[index] == nullptr) {
                temp->children[index] = new Trie(s[i]);
            }
            temp = temp->children[index];
        }
        temp->setEnd();
    }

    void print() {
        string s;
        doPrint(s);
    }

    vector<string> search(const string &word, const int limit) {
        vector<string> ret;
        string one;

        Trie *temp = this;
        int index;
        for(int i = 0; i < word.length(); i++) {
            index = word[i] - 'a';
            temp = temp->children[index];
            if (temp == nullptr) break;
            one += word[i];
        }
        if (temp != nullptr) {
            one.pop_back();
            temp->doListAll(ret, one, limit);
        }

        return ret;
    }

    void doListAll(vector<string> &ret, string &one, const int limit) {
        if(ret.size() >= limit) return;
        one += key;
        if (isEnd) ret.push_back(one);
        for (int i = 0; i < 26; i++) {
            if (children[i] == nullptr) continue;
            children[i]->doListAll(ret, one, limit);
        }
        one.pop_back();
    }

    void doSearch(vector<string> &ret, string &one, const string &word, const int index) {
        if (index >= word.length()) return;
        one += word[index];
        if (isEnd) ret.push_back(one);
        for (int i = 0; i < 26; i++) {
            if (children[i] == nullptr) continue;
            children[i]->doSearch(ret, one, word, index + 1);
        }
        one.pop_back();
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        vector<vector<string>> ans;
        // 1. use a naive prefix map. passed, but slow
//        map<string, vector<string>> prefix;
//        for(const auto &product: products) {
//            for(int i = 1; i <= product.length(); i++) {
//                prefix[product.substr(0, i)].push_back(product);
//            }
//        }
//
//        vector<string> temp(3);
//        for(int i = 1; i <= searchWord.length(); i++) {
//            temp.clear();
//            string key = searchWord.substr(0, i);
//            sort(prefix[key].begin(), prefix[key].end());
//            // get the first three
//            for(int j = 0; j < min(3, (int)prefix[key].size()); j++) {
//                temp.push_back(prefix[key][j]);
//            }
//            ans.push_back(temp);
//        }
        auto trie = new Trie('\0');
        for (const auto &product: products) {
            trie->insert(product);
        }
//        cout << "search: " << endl;
//        auto temp = trie->search("mou", 3);
//        for(const auto &w: temp) {
//            cout << w << ", " << endl;
//        }

        for(int i = 1; i <= searchWord.length(); i++) {
            ans.push_back(trie->search(searchWord.substr(0, i), 3));
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<vector<string>> ans;
    vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"}; string searchWord = "mouse";
    products = {"havana"}, searchWord = "havana";
    ans = sol.suggestedProducts(products, searchWord);
    for (const auto &group: ans) {
        for (const auto &word: group) {
            cout << word << ", ";
        }
        cout << endl;
    }
    cout << endl;
}
        