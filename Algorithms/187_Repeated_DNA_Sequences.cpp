#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

inline int dnaCode(char c) {
    switch (c) {
    case 'A': return 0;
    case 'T': return 1;
    case 'G': return 2;
    case 'C': return 3;
    }
    return -1;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string& s) {
        static const int REPEATED_LENGTH = 10;

        vector<string> result;

        unordered_map<int, int> occurs;
        for (size_t i = 0; i + REPEATED_LENGTH <= s.size(); ++i) {
            int code = this->hashDna(s, i, i + REPEATED_LENGTH);
            occurs[code]++;

            if (occurs[code] == 2) {
                result.push_back(s.substr(i, REPEATED_LENGTH));
            }
        }

        return result;
    }

private:
    // The KEY!!!
    int hashDna(const string& s, size_t begin, size_t end) {
        int hash = 0;
        while (begin < end) {
            hash = hash * 4 + dnaCode(s[begin++]);
        }
        return hash;
    }
};
