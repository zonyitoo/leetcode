#include <vector>
#include <string>
#include <algorithm>
#include <map>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> anagrams(const vector<string> &strs) {
        /*
            Given an array of strings, return all groups of strings that are anagrams.

            Note: All inputs will be in lower-case.
        */

        using std::sort;
        using std::move;
        using std::map;
        map<string, vector<vector<string>::const_iterator>> tmp;
        for (auto sitr = strs.begin(); sitr != strs.end(); ++sitr) {
            string str(*sitr);
            sort(str.begin(), str.end());
            auto itr = tmp.find(str);
            if (itr != tmp.end()) {
                itr->second.push_back(sitr);
            } else {
                tmp[str] = vector<vector<string>::const_iterator>(1, sitr);
            }
        }

        vector<string> result;
        for (auto p : tmp) {
            if (p.second.size() >= 2) {
                for (auto itr : p.second) {
                    result.push_back(*itr);
                }
            }
        }

        return result;
    }
};
