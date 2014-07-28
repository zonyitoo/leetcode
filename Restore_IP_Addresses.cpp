#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

class Solution {
public:
    vector<string> restoreIpAddresses(const string &s) {
        vector<string> ips;
        vector<string> buf;
        process(ips, buf, s, 0);
        return ips;
    }

    void process(vector<string> &ips, vector<string> &buf, const string &s, int pos) {
        if (buf.size() == 3) {
            int remain = s.size() - pos;
            if (remain == 1 || (remain <= 3 && s[pos] != '0')) {
                string subs = s.substr(pos);
                if (atoi(subs.c_str()) > 255)
                    return;
                stringstream ss;
                ss << buf[0] << "." << buf[1] << "." << buf[2] << "." << subs;
                ips.push_back(ss.str());
            }
            return;
        }

        for (int i = 1; i <= 3; ++ i) {
            if (i + pos >= s.size()) {
                return;
            }
            if (i != 1 && s[pos] == '0') {
                return;
            }
            string subs = s.substr(pos, i);
            if (atoi(subs.c_str()) <= 255) {
                buf.push_back(s.substr(pos, i));
                process(ips, buf, s, pos + i);
                buf.pop_back();
            }
        }
    }
};

#include <iostream>
using namespace std;

int main() {
    vector<string> result = Solution().restoreIpAddresses("172162541");
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\" ";
    }
    cout << "]" << endl;
    return 0;
}
