#include "leetcode.hpp"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        const size_t left_pos = this->findPointInInterval(intervals, newInterval.start);
        const size_t right_pos = this->findPointInInterval(intervals, newInterval.end);

        if (left_pos == intervals.size()) {
            intervals.push_back(newInterval);
        } else {
            if (left_pos != right_pos) {
                this->mergeIntervals(intervals, left_pos, right_pos - 1);
            }

            if (newInterval.end < intervals[left_pos].start) {
                intervals.insert(intervals.begin() + left_pos, newInterval);
            } else {
                intervals[left_pos].start = std::min(intervals[left_pos].start, newInterval.start);

                const size_t new_right = left_pos + 1;
                if (new_right != intervals.size()) {
                    if (newInterval.end < intervals[new_right].start) {
                        intervals[left_pos].end = std::max(intervals[left_pos].end, newInterval.end);
                    } else {
                        this->mergeIntervals(intervals, left_pos, new_right);
                    }
                }

                intervals[left_pos].end = std::max(intervals[left_pos].end, newInterval.end);
            }
        }

        return intervals;
    }

private:
    size_t findPointInInterval(const vector<Interval>& intervals, int point) const {
        if (intervals.empty()) {
            return 0;
        }

        size_t left = 0, right = intervals.size() - 1;

        while (left <= right) {
            if (point <= intervals[left].start) {
                return left;
            } else if (point > intervals[right].end) {
                return right + 1;
            }

            const size_t mid = (left + right) / 2;
            if (point < intervals[mid].start) {
                right = mid;
            } else if (point > intervals[mid].end) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return 0;
    }

    void mergeIntervals(vector<Interval>& intervals, const size_t left, const size_t right) const {
        if (left >= right) return;

        intervals[left].end = intervals[right].end;
        intervals.erase(intervals.begin() + left + 1,
        intervals.begin() + right + 1);
    }
};
