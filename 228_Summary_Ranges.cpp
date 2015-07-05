#include <vector>
#include <string>
using std::vector;
using std::string;


class Solution {
  public:
    vector<string> summaryRanges(const vector<int>& nums) {
        if (nums.empty()) return {};

        vector<string> result;

        int begin = nums[0];
        int prev = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != prev + 1) {

                if (prev != begin) {
                    string val = std::to_string(begin) + "->" + std::to_string(prev);
                    result.push_back(val);
                } else {
                    result.push_back(std::to_string(begin));
                }

                begin = nums[i];
            }

            prev = nums[i];
        }

        if (prev != begin) {
            string val = std::to_string(begin) + "->" + std::to_string(prev);
            result.push_back(val);
        } else {
            result.push_back(std::to_string(begin));
        }

        return std::move(result);
    }
};
