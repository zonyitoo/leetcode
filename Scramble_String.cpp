#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isScramble(const string &s1, const string &s2) const {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;

        return solve(s1.begin(), s1.end(), s2.begin(), s2.end());
    }

private:

    bool solve(string::const_iterator s1_beg, string::const_iterator s1_end,
               string::const_iterator s2_beg, string::const_iterator s2_end) const {
        if (equal(s1_beg, s1_end, s2_beg)) return true;

        unordered_multiset<char> s1, s2;
        for (auto itr1 = s1_beg, itr2 = s2_beg; itr1 + 1 != s1_end; ++itr1, ++itr2) {
            s1.insert(*itr1);
            s2.insert(*itr2);
            if (s1 == s2) {
                if (solve(s1_beg, itr1 + 1, s2_beg, itr2 + 1)
                        && solve(itr1 + 1, s1_end, itr2 + 1, s2_end)) {
                    return true;
                }
            }
        }

        s1.clear();
        s2.clear();
        for (auto itr1 = s1_beg, itr2 = s2_end; itr1 != s1_end - 1; ++itr1, --itr2) {
            s1.insert(*itr1);
            s2.insert(*(itr2 - 1));
            if (s1 == s2) {
                if (solve(s1_beg, itr1 + 1, itr2 - 1, s2_end)
                        && solve(itr1 + 1, s1_end, s2_beg, itr2 - 1)) {
                    return true;
                }
            }
        }

        return false;
    }

};
