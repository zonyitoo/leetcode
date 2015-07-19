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

        string result = sstream.str();
        std::reverse(result.begin(), result.end());
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
