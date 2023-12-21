// https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2023-12-17
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
struct Food {
    string name;
    int rating;

    Food(const string &name, int rating) : name(name), rating(rating) {}

    bool operator<(const Food &other) const {
        if (rating == other.rating) {
            return name > other.name;
        }
        return rating < other.rating;
    }
};

class FoodRatings {
private:
    unordered_map<string, priority_queue<Food>> cuisine2food;
    unordered_map<string, string> food2cuisine;
    unordered_map<string, int> food2rating;
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        ios_base::sync_with_stdio(false);
        for (int i = 0; i < foods.size(); i++) {
            cuisine2food[cuisines[i]].emplace(foods[i], ratings[i]);
            food2cuisine[foods[i]] = cuisines[i];
            food2rating[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = food2cuisine[food];
        food2rating[food] = newRating;
        cuisine2food[cuisine].push(Food(food, newRating));
    }

    string highestRated(string cuisine) {
        auto top = cuisine2food[cuisine].top();
        while (top.rating != food2rating[top.name]) {
            cuisine2food[cuisine].pop();
            top = cuisine2food[cuisine].top();
        }
        return cuisine2food[cuisine].top().name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
//#####

// do not copy lines after this to LeetCode
int main() {
    vector<string> foods{"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines{"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings{9, 12, 8, 15, 14, 7};
    FoodRatings *obj = new FoodRatings(foods, cuisines, ratings);
    cout << obj->highestRated("korean") << endl;
    cout << obj->highestRated("japanese") << endl;
    obj->changeRating("sushi", 16);
    cout << obj->highestRated("japanese") << endl;
    obj->changeRating("ramen", 16);
    cout << obj->highestRated("japanese") << endl;
}
        