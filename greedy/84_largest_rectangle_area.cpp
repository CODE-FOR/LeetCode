#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> boundary;
        int largest_rectangle_area = 0;
        // dummy_end
        heights.push_back(-1);
        vector<int> area = vector<int>(heights.size(), 0);
        for (int i = 0; i < heights.size(); i++) {
            while (!boundary.empty() && heights[boundary.top()] >= heights[i]) {
                area[boundary.top()] += heights[boundary.top()] * (i - boundary.top() - 1);
                if (area[boundary.top()] > largest_rectangle_area) {
                    largest_rectangle_area = area[boundary.top()];
                }
                boundary.pop();
            }
            int left_boundary = boundary.empty() ? -1 : boundary.top();
            area[i] += heights[i] * (i - left_boundary);
            boundary.push(i);
        }
        return largest_rectangle_area;
    }
};