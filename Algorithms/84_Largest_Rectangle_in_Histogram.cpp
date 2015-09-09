#include "leetcode.hpp"

#include <stack>
#include <algorithm>
using std::stack;

class Solution {
public:
    int largestRectangleArea(const vector<int>& height) {
        stack<size_t> heights;

        int largest_area = 0;

        for (size_t i = 0; i <= height.size();) {
            const int h = (i == height.size()) ? 0 : height[i];

            if (heights.empty() || h >= height[heights.top()]) {
                heights.push(i++);
            } else {
                const size_t top = heights.top();
                heights.pop();

                const size_t width = (heights.empty()) ? i : (i - heights.top() - 1);
                const int area = height[top] * width;
                largest_area = std::max(area, largest_area);
            }
        }

        return largest_area;
    }
};
