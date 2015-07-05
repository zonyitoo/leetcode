#include <string>
using std::string;
#include <sstream>
using std::stringstream;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        }
        string result = "1";
        while (--n) {
            stringstream tmp;
            int counter = 1;
            char curchar = result[0];
            for (int i = 1; i < result.size(); ++i) {
                if (result[i] != curchar) {
                    tmp << counter << curchar;
                    counter = 1;
                    curchar = result[i];
                } else {
                    counter++;
                }
            }
            tmp << counter << curchar;
            result = tmp.str();
        }
        return result;
    }
};

