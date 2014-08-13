#include <vector>
using std::vector;
using std::swap;
#include <algorithm>
using std::reverse;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        __next_perm(num.begin(), num.end());
    }

private:
    bool __next_perm(vector<int>::iterator beg, vector<int>::iterator end) {
        if (beg == end) {
            return false;
        }

        vector<int>::iterator i = beg;
        ++i;
        if (i == end) {
            return false;
        }

        i = end;
        --i;

        for (;;) {
            vector<int>::iterator ii = i;
            --i;
            if (*i < *ii) {
                vector<int>::iterator j = end;
                while (!(*i < *--j));

                std::iter_swap(i, j);
                reverse(ii, end);
                return true;
            }

            if (i == beg) {
                reverse(beg, end);
                return false;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> num {1, 1, 5};
    while (true) {
        s.nextPermutation(num);
        for (auto &item : num) {
            printf("%d ", item);
        }
        printf("\n");
    }
    return 0;
}
