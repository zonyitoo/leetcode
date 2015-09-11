#include "leetcode.hpp"

#include <algorithm>
#include <unordered_map>
#include <limits>

bool is_same_point(Point const& a, Point const& b) {
    return a.x == b.x && a.y == b.y;
}

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(const vector<Point>& points) {

        int max_points = 0;

        for (size_t i = 0; i < points.size(); ++i) {
            int same_point = 0;
            unordered_map<double, int> counts;
            int cur_max = 0;
            for (size_t j = i + 1; j < points.size(); ++j) {
                if (is_same_point(points[i], points[j])) {
                    ++same_point;
                } else {
                    double slope = std::numeric_limits<double>::infinity();
                    if (points[i].x != points[j].x) {
                        slope = static_cast<double>(points[i].y - points[j].y)
                                    / static_cast<double>(points[i].x - points[j].x);
                    }

                    counts[slope] += 1;
                    cur_max = std::max(counts[slope], cur_max);
                }
            }

            cur_max += 1 + same_point;
            max_points = std::max(cur_max, max_points);
        }

        return max_points;
    }
};
