#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> findSubstring(const string& s, const vector<string>& words) {
        vector<int> result;
        if (words.empty()) {
            return std::move(result);
        }

        unordered_map<string, size_t> dict;
        for (const auto& s : words) {
            dict[s] += 1;
        }

        const size_t word_length = words[0].size();
        const size_t length = word_length * words.size();
        for (size_t i = 0; i + length <= s.size(); ++i) {
            const string sub_str = s.substr(i, length);

            unordered_map<string, size_t> in_window;
            bool is_found = true;
            for (const auto pair : dict) {
                size_t pos = 0;
                bool is_found_inner = false;
                while ((pos = sub_str.find(pair.first, pos)) != string::npos) {
                    if (pos % word_length == 0) {
                        is_found_inner = true;
                        in_window[pair.first] += 1;
                    }

                    pos += 1;
                }

                if (!is_found_inner) {
                    is_found = false;
                    break;
                }
            }

            if (!is_found) {
                continue;
            }


            if (in_window.size() != dict.size()) {
                continue;
            }

            is_found = true;
            for (const auto pair : in_window) {
                if (dict[pair.first] != pair.second) {
                    is_found = false;
                    break;
                }
            }

            if (is_found) {
                result.push_back(i);
            }
        }

        return result;
    }
};
