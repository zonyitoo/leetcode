#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result {n, -1};

        search(A, 0, n - 1, target, result[1], result[0]);
        if (result[0] == n) {
            result[0] = -1;
        }

        return result;
    }

private:
    void search(int A[], int beg, int end, int target, int &max_pos, int &min_pos) {
        if (beg > end) return;
        int mid = (beg + end) / 2;
        if (A[mid] == target) {
            if (max_pos < mid) {
                max_pos = mid;
            }
            if (min_pos > mid) {
                min_pos = mid;
            }
            search(A, beg, mid - 1, target, max_pos, min_pos);
            search(A, mid + 1, end, target, max_pos, min_pos);
        } else if (A[mid] < target) {
            search(A, mid + 1, end, target, max_pos, min_pos);
        } else {
            search(A, beg, mid - 1, target, max_pos, min_pos);
        }
    }
};

int main() {
    int arr[] = {5, 7, 7, 8, 8, 10};
    auto result = Solution().searchRange(arr, 6, 8);
    for (auto &item : result) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
