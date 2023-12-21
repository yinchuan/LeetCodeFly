// https://leetcode.com/problems/minimum-genetic-mutation/description/
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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // assume end in bank, otherwise checkfisrt
        int ans = 0;

        // from startGene, find all mutations with distance 1
        // if see endGene, done, otherwise continue from those mutations
        queue<string> q;
        unordered_map<string, bool> visited;
        q.push(startGene);

        while(!q.empty()) {
            ans++;

            for(int size = q.size(); size > 0; size--) { // BFS layer by layer
                auto front = q.front();
                q.pop();
                visited[front] = true;

                for(int i = 0; i < bank.size(); i++) {
                    if (visited[bank[i]]) continue;

                    auto d = distance(front, bank[i]);

                    if (d != 1) {
                        continue;
                    }

                    if (bank[i] == endGene) {
                        return ans;
                    } else {
                        q.push(bank[i]);
                    }
                }
            }   
        }

        return -1;
    }

    int distance(const string &a, const string &b) {
        int ret = 0;
        for(int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                ret++;
            }
        }
        return ret;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string startGene;
string endGene;
vector<string> bank;

    startGene=;
endGene=;
bank;
    ans = sol.minMutation(startGene, endGene, bank);
    std::cout << ans << std::endl;
}
        