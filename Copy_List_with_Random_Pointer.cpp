#include "leetcode.hpp"

#include <map>
using std::map;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> nexts;
        RandomListNode *newhead = nullptr;
        RandomListNode **newpnt = &newhead, *pnt = head;
        while (pnt != nullptr) {
            auto itr = nexts.find(pnt);
            if (itr != nexts.end()) {
                *newpnt = itr->second;
            } else {
                *newpnt = new RandomListNode(pnt->label);
                nexts[pnt] = *newpnt;
            }

            if (pnt->random != nullptr) {
                itr = nexts.find(pnt->random);
                if (itr != nexts.end()) {
                    (*newpnt)->random = itr->second;
                } else {
                    RandomListNode *newnext = new RandomListNode(pnt->random->label);
                    (*newpnt)->random = newnext;
                    nexts[pnt->random] = newnext;
                }
            }

            newpnt = &(*newpnt)->next;
            pnt = pnt->next;
        }
        return newhead;
    }
};
