#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using std::string;
using std::vector;

class Solution {
public:
    string largestNumber(const vector<int>& nums) {
        vector<string> numstrs;
        numstrs.reserve(nums.size());
        for (int n : nums) {
            numstrs.push_back(std::to_string(n));
        }

        std::sort(numstrs.begin(), numstrs.end(), [](const string & a, const string & b) {
            return a + b > b + a;
        });

        std::stringstream sstream;
        for (const string& s : numstrs) {
            sstream << s;
        }

        return std::move(sstream.str());
    }
};
