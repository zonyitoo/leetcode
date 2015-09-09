#include "leetcode.hpp"

#include <iterator>

class Solution {
public:
    vector<string> wordBreak(const string& s, const unordered_set<string>& wordDict) {
        vector<string> result;
        if (wordDict.empty() || s.empty()) {
            return std::move(result);
        }

        vector<bool> possible(s.size() + 1, true);
        vector<string> stack;
        this->recursiveSolve(result, stack, possible, s.cbegin(), s, wordDict);

        return std::move(result);
    }

private:
    void recursiveSolve(vector<string>& result,
                        vector<string>& stack,
                        vector<bool>& possible,
                        string::const_iterator beg,
                        const string& s,
                        const unordered_set<string>& wordDict
                        //const TireTree& tire
                        ) const {
        const size_t idx = std::distance(s.cbegin(), beg);
        if (beg == s.cend()) {
            string s(stack[0]);
            for (size_t i = 1; i < stack.size(); ++i) {
                s.push_back(' ');
                s.append(stack[i]);
            }
            result.push_back(std::move(s));
            return;
        }

        bool is_possible = false;

        for (const auto& word : wordDict) {
            const size_t pos = s.find(word, idx);
            if (pos == idx) {
                if (!possible[idx + word.size()]) {
                    continue;
                }

                is_possible = true;
                stack.push_back(word);
                this->recursiveSolve(result, stack, possible, beg + word.size(), s, wordDict);
                stack.pop_back();
            }
        }

        possible[idx] = is_possible;
    }
};
