// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/?envType=daily-question&envId=2023-11-28
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
public:
    int numberOfWays(string corridor) {
        enum states {
            START, ONE_SEAT, TWO_SEATS, PLANT
        };

        enum states state = START;
        int seats = 0;
        int plants = 0;
        int ans = 1;
        for (const char ch: corridor) {
            switch (state) {
                case START:
                    if (ch == 'S') state = ONE_SEAT;
                    break;
                case ONE_SEAT:
                    if (ch == 'S') state = TWO_SEATS;
                    break;
                case TWO_SEATS:
                    if (ch == 'P') {
                        state = PLANT;
                        plants++;
                    } else {
                        // reset counter
                        seats = 1;
                        plants = 0;
                        state = ONE_SEAT;
                    }
                    break;
                case PLANT:
                    if (ch == 'P') {
                        plants++;
                    } else {
                        // save result, reset counter
                        ans = (ans * (plants + 1)) % (1000000000 + 7);
                        seats = 1;
                        plants = 0;
                        state = ONE_SEAT;
                    }
                    break;
                default:
                    break;
            }

        }

        switch (state) {
            case TWO_SEATS:
            case PLANT:
                return ans;
            case START:
            case ONE_SEAT:
            default:
                return 0;
        }
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string corridor;

    corridor = "SSPPSPS";
//    corridor = "PPSPSP";
//    corridor = "S";
//    corridor = "SS";
//    corridor = "SSP";
//    corridor = "SSPP";
//    corridor = "PSPS";
//    corridor = "SSSPPPSPPSPSSSSSSPPPSPP";
    corridor = "PPPPPPPSPPPSPPPPSPPPSPPPPPSPPPSPPSPPSPPPPPSPSPPPPPSPPSPPPPPSPPSPPSPPPSPPPPSPPPPSPPPPPSPSPPPPSPSPPPSPPPPSPPPPPSPSPPSPPPPSPPSPPSPPSPPPSPPSPSPPSSSS";
    ans = sol.numberOfWays(corridor);
    std::cout << ans << std::endl;
}
        