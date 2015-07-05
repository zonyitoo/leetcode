#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> fullJustify(const vector<string> &words, int L) {
        vector<string> result;

        auto beg = words.begin();
        int counter = beg->length();
        auto itr = beg + 1;
        while (itr != words.end()) {
            if (counter + itr->length() + (itr - beg) + 1 > L) {
                int spaces = L - counter;
                int each = spaces / (itr - beg - 1);
                string tmp = *(beg++);
                while (beg + 1 != itr) {
                    tmp.append(each, ' ');
                    tmp.append(*(beg++));
                }
                tmp.append(each, ' ');
                int rest = L - (tmp.size() + beg->size()) + 1;
                while (rest--) {
                    tmp.push_back(' ');
                }
                tmp.append(*beg);
                result.push_back(tmp);
                beg = itr;
                counter = 0;
            } else {
                counter += itr->length();
                ++itr;
            }
        }

        int spaces = L - counter;
        int each = (itr != beg && itr != beg + 1) ? spaces / (itr - beg - 1) : spaces;
        string tmp = *(beg++);
        while (beg != itr && beg + 1 != itr) {
            tmp.append(each, ' ');
            tmp.append(*(beg++));
        }
        tmp.append(each, ' ');
        int rest = (each != 0) ? L - (tmp.size() + beg->size()) + 1 : 0;
        while (rest--) {
            tmp.push_back(' ');
        }
        tmp.append(*beg);
        result.push_back(tmp);

        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto ret = s.fullJustify({"This", "is", "an", "example", "of", "text", "justification."}, 16);
    for (auto &item : ret) {
        cout << "[" << item << "]" << endl;
    }
    cout << endl;
    ret = s.fullJustify({""}, 0);
    for (auto &item : ret) {
        cout << "[" << item << "]" << endl;
    }
    return 0;
}
