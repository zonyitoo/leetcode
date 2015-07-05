#include <unordered_set>

class Solution {
  public:
    bool isHappy(int n) {

        std::unordered_set<int> set;
        set.insert(n);

        int cur = n;

        while (cur != 1) {
            cur = calc(cur);

            if (set.find(cur) != set.end()) return false;
            set.insert(cur);
        }

        return true;
    }

  private:
    int calc(int cur) {
        int tmp = 0;
        while (cur != 0) {
            int t = cur % 10;
            tmp += t * t;
            cur /= 10;
        }

        return tmp;
    }
};

#include <cassert>

int main() {
    assert(Solution().isHappy(2));
    return 0;
}

