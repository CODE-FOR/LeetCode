#include <iostream>
#include <stack>

using std::stack;

class MyQueue {

private:
    stack<int> stack_for_buffer;
    stack<int> stack_for_output;

public:
    MyQueue() {
    }
    
    void push(int x) {
        stack_for_buffer.push(x);
    }

    void put_buffer_element_into_empty_output() {
        while(!stack_for_buffer.empty()) {
            stack_for_output.push(stack_for_buffer.top());
            stack_for_buffer.pop();
        }
    }
    
    int pop() {
        if (stack_for_output.empty()) {
            put_buffer_element_into_empty_output();
        }
        int res = stack_for_output.top();
        stack_for_output.pop();
        return res;
    }
    
    int peek() {
        if (stack_for_output.empty()) {
            put_buffer_element_into_empty_output();
        }
        return stack_for_output.top();
    }
    
    bool empty() {
        return stack_for_buffer.empty() && stack_for_output.empty();
    }
};
