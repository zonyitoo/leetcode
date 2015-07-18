#include <vector>
#include <list>
#include <queue>
using std::vector;
using std::pair;
using std::list;
using std::queue;

struct Node {
    size_t incoming;
    int course;
    list<Node *> edges;

    explicit Node(int c)
        : incoming(0)
        , course(c)
    {}
};

class Solution {
public:
    bool canFinish(const int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<Node> nodes;
        for (int i = 0; i < numCourses; ++i) {
            nodes.emplace_back(i);
        }

        for (const auto& prereq : prerequisites) {
            const int to_take = prereq.first;
            const int pre_take = prereq.second;

            nodes[pre_take].edges.emplace_front(&nodes[to_take]);
            nodes[to_take].incoming += 1;
        }

        vector<int> ans;
        queue<int> q;
        for (const Node& n : nodes) {
            if (n.incoming == 0) {
                q.push(n.course);
            }
        }

        while (!q.empty()) {
            const int nidx = q.front();
            q.pop();

            ans.push_back(nidx);

            while (!nodes[nidx].edges.empty()) {
                Node *next_node = nodes[nidx].edges.front();
                next_node->incoming -= 1;

                if (next_node->incoming == 0) {
                    q.push(next_node->course);
                }

                nodes[nidx].edges.pop_front();
            }
        }

        return ans.size() == numCourses;
    }
};
