#include <stack>

class Queue {
  public:
    // Push element x to the back of queue.
    void push(int x) {
        outputs_to_inputs();
        inputs.push(x);
        inputs_to_outputs();
    }

    // Removes the element from in front of queue.
    void pop(void) {
        return outputs.pop();
    }

    // Get the front element.
    int peek(void) {
        return outputs.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return outputs.empty();
    }

  private:
    std::stack<int> inputs;
    std::stack<int> outputs;

    void outputs_to_inputs() {
        while (!outputs.empty()) {
            inputs.push(outputs.top());
            outputs.pop();
        }
    }

    void inputs_to_outputs() {
        while (!inputs.empty()) {
            outputs.push(inputs.top());
            inputs.pop();
        }
    }
};
