#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
  public:
    string largestNumber(const vector<int>& nums) {
        vector<string> numstrs;
        for (int num : nums) {
            numstrs.push_back(std::to_string(num));
        }

        std::sort(numstrs.begin(), numstrs.end(), [](const string & a, const string & b) {
            for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
                if (a[i] != b[i]) return a[i] > b[i];
            }

            if (a.size() > b.size()) {

                if (b.back() >= a[0]) {
                    return false;
                } else {
                    return a[b.size()] > b[0];
                }

            } else if (a.size() < b.size()) {

                if (a.back() >= b[0]) {
                    return true;
                } else {
                    return b[a.size()] < a[0];
                }

            } else {
                return false;
            }
        });

        string result;
        for (const auto& str : numstrs) {
            result.append(str);
        }

        std::reverse(result.begin(), result.end());
        while (result.size() > 1 && result.back() == '0') result.pop_back();
        std::reverse(result.begin(), result.end());

        return std::move(result);
    }
};

#include <iostream>
using std::cout;
using std::endl;
#include <cassert>

int main() {
    // vector<int> v {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // vector<int> v {824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};

    // vector<int> v {121, 12};

    vector<int> v {4704, 6306, 9385, 7536, 3462, 4798, 5422, 5529, 8070, 6241, 9094, 7846, 663, 6221, 216, 6758, 8353, 3650, 3836, 8183, 3516, 5909, 6744, 1548, 5712, 2281, 3664, 7100, 6698, 7321, 4980, 8937, 3163, 5784, 3298, 9890, 1090, 7605, 1380, 1147, 1495, 3699, 9448, 5208, 9456, 3846, 3567, 6856, 2000, 3575, 7205, 2697, 5972, 7471, 1763, 1143, 1417, 6038, 2313, 6554, 9026, 8107, 9827, 7982, 9685, 3905, 8939, 1048, 282, 7423, 6327, 2970, 4453, 5460, 3399, 9533, 914, 3932, 192, 3084, 6806, 273, 4283, 2060, 5682, 2, 2362, 4812, 7032, 810, 2465, 6511, 213, 2362, 3021, 2745, 3636, 6265, 1518, 8398};

    auto ret = Solution().largestNumber(v);
    cout << ret << endl;

    assert(ret == "98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048");
    return 0;
}
