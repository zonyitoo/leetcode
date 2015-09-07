// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return this->findBadVersion(n);
    }

private:
    int findBadVersion(int n) const {
        int left = 1;
        int right = n;

        while (left < right) {
            const int mid = (static_cast<long>(left) + static_cast<long>(right)) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
