class Tire:

    class Node:

        def __init__(self):
            self.nexts = dict()
            self.is_end = False

    def __init__(self):
        self.root = Tire.Node()

    def add_string(self, string):
        cur = self.root
        for c in string:
            if c not in cur.nexts:
                cur.nexts[c] = Tire.Node()
            cur = cur.nexts[c]
        cur.is_end = True

    def longest_common_prefix(self):
        cur = self.root
        chars = []
        while cur is not None:
            if len(cur.nexts) != 1 or cur.is_end is True:
                break
            key = cur.nexts.keys()[0]
            chars.append(key)
            cur = cur.nexts[key]
        return ''.join(chars)


class Solution:

    # @return a string
    def longestCommonPrefix(self, strs):
        t = Tire()
        for s in strs:
            t.add_string(s)
        return t.longest_common_prefix()
