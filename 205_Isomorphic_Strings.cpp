#include <string>
using std::string;

class Solution {
  public:
    bool isIsomorphic(const string& s, const string& t) {
        char convert[256] = {0};
        bool used[256] = {0};

        for (size_t i = 0; i < s.size(); ++i) {
            if (convert[static_cast<int>(s[i])] == 0) {
                if (used[static_cast<int>(t[i])]) return false;
                used[static_cast<int>(t[i])] = true;
                convert[static_cast<int>(s[i])] = t[i];
            } else if (convert[static_cast<int>(s[i])] != t[i]) {
                return false;
            }
        }

        return true;
    }
};
