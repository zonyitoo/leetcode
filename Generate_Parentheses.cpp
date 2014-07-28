#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) {
            return result;
        }

        string stack;
        solve(result, stack, n, n);
        return result;
    }

private:
    void solve(vector<string> &result, string &stack, int leftn, int rightn) {
        if (leftn == 0 && rightn == 0) {
            result.push_back(stack);
        }
        stack.push_back('(');
        if (leftn != 0) {
            solve(result, stack, leftn - 1, rightn);
        }
        if (rightn > leftn) {
            stack.back() = ')';
            solve(result, stack, leftn, rightn - 1);
        }
        stack.pop_back();
    }
};

#include <iostream>
using std::cout;
using std::endl;

int main() {
    auto ret = Solution().generateParenthesis(3);
    for (auto &item : ret) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
