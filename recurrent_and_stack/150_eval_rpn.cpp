#include <vector>
#include <string>
#include <stack>

using std::stack;
using std::vector;
using std::string;
using std::stoi;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> num_stack = stack<long long> ();
        for (auto &token : tokens) {
            if (token == "+") {
                long long right = num_stack.top();
                num_stack.pop();
                long long left = num_stack.top();
                num_stack.pop();
                long long res = left + right;
                num_stack.push(res);
            } else if (token == "-") {
                long long right = num_stack.top();
                num_stack.pop();
                long long left = num_stack.top();
                num_stack.pop();
                long long res = left - right;
                num_stack.push(res);
            } else if (token == "*") {
                long long right = num_stack.top();
                num_stack.pop();
                long long left = num_stack.top();
                num_stack.pop();
                long long res = left * right;
                num_stack.push(res);
            } else if (token == "/") {
                long long right = num_stack.top();
                num_stack.pop();
                long long left = num_stack.top();
                num_stack.pop();
                long long res = left / right;
                num_stack.push(res);
            } else {
                num_stack.push(stoi(token));
            }
        }
        return num_stack.top();
        
    }
};