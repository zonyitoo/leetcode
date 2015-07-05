#include <vector>
#include <queue>
#include <functional>
using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
  public:
    int findKthLargest(const vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;

        for (const auto& num : nums) {
            heap.push(num);

            while (heap.size() > k) {
                heap.pop();
            }
        }

        return heap.top();
    }
};

#include <cstdio>

int main() {
    int ret = Solution().findKthLargest({3, 2, 1, 5, 6, 4}, 2);
    printf("%d\n", ret);
}
