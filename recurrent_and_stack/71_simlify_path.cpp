#include <string>
#include <stack>


using std::stack;
using std::string;

class Solution {
public:
    string simplifyPath(string path) {
        stack path_stack = stack<string> ();
        string path_part = "";
        path = path + "/";
        for (auto &c : path) {
            if (c == '/') {
                if (path_part == "") {
                    continue;
                } else if (path_part == "..") {
                    if (!path_stack.empty()) {
                        path_stack.pop();
                    }
                } else if (path_part != ".") {
                    path_stack.push(path_part);
                }
                path_part = "";
            } else {
                path_part += c; 
            }
        }
        string simplify_path = "";
        while (!path_stack.empty()) {
            simplify_path = "/" + path_stack.top() + simplify_path; 
            path_stack.pop();
        }
        return simplify_path == "" ? "/" : simplify_path;
    }
}; 