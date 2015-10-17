#include "leetcode.hpp"

#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(const string& pattern, const string& str) {
        unordered_map<char, string> pat2str;
        unordered_map<string, char> str2pat;

        int last = 0;
        int i = 0, pidx = 0;
        for (; i <= (int)str.size() && pidx < (int)pattern.size(); ++i) {
            if (i == (int)str.size() || str[i] == ' ') {
                const string sstr = str.substr(last, i - last);
                if (sstr == "") {
                    return false;
                }

                last = i + 1;

                const auto itr2 = pat2str.find(pattern[pidx]);
                if (itr2 != pat2str.end()) {
                    if (itr2->second != sstr) {
                        return false;
                    }

                    ++pidx;
                    continue;
                }

                const auto itr1 = str2pat.find(sstr);
                if (itr1 != str2pat.end()) {
                    return false;
                }

                str2pat.emplace(sstr, pattern[pidx]);
                pat2str.emplace(pattern[pidx], std::move(sstr));
                ++pidx;
            }
        }

        if (i <= (int)str.size() || pidx < (int)pattern.size()) {
            return false;
        }

        return true;
    }
};
