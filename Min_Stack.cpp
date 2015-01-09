#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        realStack.push(x);
        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
    }

    void pop() {
        int top = this->top();
        realStack.pop();
        if (!minStack.empty() && minStack.top() == top) {
            minStack.pop();
        }
    }

    int top() {
        return realStack.top();
    }

    int getMin() {
        return minStack.top();
    }

private:
    stack<int> realStack;
    stack<int> minStack;
};
