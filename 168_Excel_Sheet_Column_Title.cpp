#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n != 0) {
            n -= 1;
            ans.push_back(n % 26 + 'A');
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
