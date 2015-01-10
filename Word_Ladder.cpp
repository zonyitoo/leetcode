#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int ladderLength(const string &start, const string &end, const unordered_set<string> &dict) const {
        vector<const string *> trans;
        trans.push_back(&start);
        trans.push_back(&end);
        for (auto &s : dict) trans.push_back(&s);
        unordered_map<const string *, size_t> revtrans;
        for (int i = 0; i < trans.size(); ++i) revtrans[trans[i]] = i;

        vector<vector<size_t>> adjmap(trans.size());
        for (int i = 0; i < trans.size(); ++i) {
            for (int j = i + 1; j < trans.size(); ++j) {
                if (diff_string(*trans[i], *trans[j]) == 1) {
                    adjmap[i].push_back(j);
                    adjmap[j].push_back(i);
                }
            }
        }

        vector<bool> visited(adjmap.size(), false);
        queue<pair<size_t, int>> q;
        visited[0] = true;
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur.first == 1) {
                return cur.second;
            }

            for (int i = 0; i < adjmap[cur.first].size(); ++i) {
                if (!visited[adjmap[cur.first][i]]) {
                    visited[adjmap[cur.first][i]] = true;
                    q.push(make_pair(adjmap[cur.first][i], cur.second + 1));
                }
            }
        }

        return 0;
    }

private:
    size_t diff_string(const string &a, const string &b) const {
        size_t diff = 0;
        int i = 0;
        for (; i < a.size() && i < b.size(); ++i) {
            if (a[i] != b[i]) ++diff;
        }

        if (i < a.size()) diff += a.size() - i;
        else if (i < b.size()) diff += b.size() - i;
        return diff;
    }
};
