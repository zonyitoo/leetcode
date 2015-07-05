#include <vector>

class Stack {
  public:
    // Push element x onto stack.
    void push(int x) {
        this->data.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        this->data.pop_back();
    }

    // Get the top element.
    int top() {
        return this->data.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return this->data.size() == 0;
    }

  private:
    std::vector<int> data;
};
