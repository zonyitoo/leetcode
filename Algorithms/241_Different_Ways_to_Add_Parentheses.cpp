#include <vector>
#include <string>
#include <cctype>
using std::vector;
using std::string;

int add_(int a, int b) { return a + b; }
int sub_(int a, int b) { return a - b; }
int mul_(int a, int b) { return a * b; }
int div_(int a, int b) { return a / b; }

typedef int(*op_t)(int, int);

class Solution {
public:
    vector<int> diffWaysToCompute(const string& input) {
        if (input.empty()) {
            return {};
        }

        vector<int> nums;
        vector<char> ops;

        int current = 0;
        for (char c : input) {
            if (std::isdigit(c)) {
                current = current * 10 + (c - '0');
            } else {
                nums.push_back(current);
                ops.push_back(c);
                current = 0;
            }
        }
        nums.push_back(current);

        vector<int> result;
        evaluate(nums, 0, nums.size() - 1, ops, &result);
        return result;
    }

private:
    void evaluate(const vector<int>& nums,
                  const size_t left_idx, const size_t right_idx,
                  const vector<char>& ops,
                  vector<int>* results) {
        if (left_idx == right_idx) {
            results->push_back(nums[left_idx]);
            return;
        }

        vector<int> left_results, right_results;
        for (size_t i = left_idx; i < right_idx; ++i) {
            left_results.clear();
            right_results.clear();

            evaluate(nums, left_idx, i, ops, &left_results);
            evaluate(nums, i + 1, right_idx, ops, &right_results);

            op_t operation = nullptr;
            switch (ops[i]) {
                case '+': operation = add_; break;
                case '-': operation = sub_; break;
                case '*': operation = mul_; break;
                case '/': operation = div_; break;
            }

            for (int left_r : left_results) {
                for (int right_r : right_results) {
                    results->push_back(operation(left_r, right_r));
                }
            }
        }
    }
};
