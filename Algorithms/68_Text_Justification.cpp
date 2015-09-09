#include "leetcode.hpp"

class Solution {
public:
    vector<string> fullJustify(const vector<string>& words, int maxWidth) {
        vector<string> result;

        if (maxWidth < 0 || words.empty()) {
            return result;
        }

        size_t from = 0;
        size_t accu = 0;
        for (size_t to = 0; to < words.size(); ++to) {
            const size_t least_spaces = to - from;
            if (accu + words[to].size() + least_spaces > static_cast<size_t>(maxWidth)) {
                // Oneline
                string line = this->joinWithSpaces(words, from, to - 1, maxWidth);
                result.push_back(line);

                accu = words[to].size();
                from = to;
            } else {
                accu += words[to].size();
            }
        }

        string line = this->lastLine(words, from, maxWidth);
        result.push_back(line);

        return result;
    }

private:
    string joinWithSpaces(const vector<string>& words, size_t from, size_t to, int max_width) {
        string result;
        result.reserve(max_width);

        if (from != to) {

            size_t total_length = 0;
            for (size_t i = from; i <= to; ++i) {
                total_length += words[i].size();
            }

            size_t consumed_words_length = words[from].size();
            result.append(words[from]);
            for (size_t i = from + 1; i < to; ++i) {
                const size_t remaining_length = max_width - result.size();
                const size_t slots = to - i + 1;
                const size_t max_spaces =
                    (remaining_length - (total_length - consumed_words_length) + slots - 1) / slots;

                result.append(max_spaces, ' ');
                result.append(words[i]);

                consumed_words_length += words[i].size();
            }

            const size_t tailing_spaces = max_width - result.size() - words[to].size();
            if (tailing_spaces != 0)
                result.append(tailing_spaces, ' ');
            result.append(words[to]);

        } else {
            // Only one word
            result.append(words[from]);
            result.append(max_width - result.size(), ' ');
        }

        return std::move(result);
    }

    string lastLine(const vector<string>& words, size_t start, int max_width) {
        string result;
        result.reserve(max_width);

        result.append(words[start]);
        for (size_t i = start + 1; i < words.size(); ++i) {
            result.append(1, ' ');
            result.append(words[i]);
        }

        result.append(max_width - result.size(), ' ');
        return std::move(result);
    }
};
