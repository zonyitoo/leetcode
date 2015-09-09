#include "leetcode.hpp"

class Solution {
public:
    string minWindow(const string& s, const string& t) {
        if (s.empty()) {
            return "";
        }

        int t_char_map[256] = {0};
        int s_char_map[256] = {0};

        for (char c : t) {
            t_char_map[static_cast<size_t>(c)] += 1;
        }

        size_t win_left = 0, win_length = s.size() + 1;
        size_t has_found_chars = 0;
        bool has_found = false;
        for (size_t start = 0, i = 0; i < static_cast<size_t>(s.size()); ++i) {
            const size_t idx = static_cast<size_t>(s[i]);

            if (t_char_map[idx] != 0) {
                // Found one candidate char
                s_char_map[idx] += 1;
                if (s_char_map[idx] <= t_char_map[idx]) {
                    has_found_chars += 1;
                }

                if (has_found_chars == static_cast<size_t>(t.size())) {
                    // Found one window [start, i], try to minimize it
                    while (t_char_map[static_cast<size_t>(s[start])] == 0
                            || s_char_map[static_cast<size_t>(s[start])] > t_char_map[static_cast<size_t>(s[start])]) {
                        s_char_map[static_cast<size_t>(s[start++])] -= 1;
                    }

                    const size_t win_size = i - start + 1;
                    if (win_size < win_length) {
                        win_left = start;
                        win_length = win_size;
                        has_found = true;
                    }

                    s_char_map[static_cast<size_t>(s[start])] -= 1;
                    start += 1;
                    has_found_chars -= 1;
                }
            }
        }

        return has_found ? s.substr(win_left, win_length) : "";
    }
};
