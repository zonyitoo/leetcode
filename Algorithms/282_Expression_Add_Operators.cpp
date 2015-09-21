#include "leetcode.hpp"

#include <cstdlib>

class Solution {
public:
    vector<string> addOperators(const string& num, int target) {
        vector<string> result;
        this->solve(num, target, 0, 0, "", result);
        return std::move(result);
    }

private:
    void solve(const string num, int target, long long diff, long long cur,
               string out, vector<string>& result) {
        if (num.empty() && cur == target) {
            result.push_back(out);
            return;
        }

        for (size_t i = 1; i <= num.size(); ++i) {
            if (i >= 2 && num[0] == '0') break;

            const string cur_str = num.substr(0, i);
            const string next = num.substr(i);
            const long long v = std::strtoll(cur_str.c_str(), nullptr, 10);

            if (out.size() > 0) {
                solve(next, target, v, cur + v, out + "+" + cur_str, result);
                solve(next, target, -v, cur - v, out + "-" + cur_str, result);
                solve(next, target, diff * v, (cur - diff) + (diff * v), out + "*" + cur_str, result);
            } else {

                solve(next, target, v, v, cur_str, result);
            }
        }
    }
};
