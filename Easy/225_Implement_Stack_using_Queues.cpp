// https://leetcode.com/problems/implement-stack-using-queues/?envType=daily-question&envId=2023-11-30
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
class MyStack {
    queue<int> *q;
public:
    MyStack() {
        q = new queue<int>();
    }
    
    void push(int x) {
        // remember current size
        int size = q->size();

        // push x to back
        q->push(x);

        // pop and push size
        for(int i = 0; i < size; i++) {
            q->push(q->front());
            q->pop();
        }
    }
    
    int pop() {
        int v = q->front();
        q->pop();
        return v;
    }
    
    int top() {
        int v = q->front();
        return v;
    }
    
    bool empty() {
        return q->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//#####

// do not copy lines after this to LeetCode
int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout <<  obj->empty() << endl;
}
        