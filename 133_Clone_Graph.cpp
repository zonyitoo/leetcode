#include "leetcode.hpp"

#include <map>
#include <queue>
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::map<int, UndirectedGraphNode *> exists;
        std::queue<UndirectedGraphNode *> q;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        exists[node->label] = root;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for (UndirectedGraphNode *node : cur->neighbors) {
                auto itr = exists.find(node->label);
                if (itr == exists.end()) {
                    UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
                    exists[node->label] = newnode;
                    exists[cur->label]->neighbors.push_back(newnode);
                    q.push(node);
                } else {
                    exists[cur->label]->neighbors.push_back(itr->second);
                }
            }
        }

        return root;
    }
};
