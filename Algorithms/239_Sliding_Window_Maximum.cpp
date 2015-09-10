#include "leetcode.hpp"

#include <queue>
using std::deque;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> ans;

        if (k <= 0 || nums.size() < static_cast<size_t>(k)) {
            return ans;
        }

        deque<int> q;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            if (q.front() == i - k) {
                q.pop_front();
            }

            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }

        return std::move(ans);
    }
};
