# Definition for an interval.
class Interval:

    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __repr__(self):
        return '[%d,%d]' % (self.start, self.end)


class SegmentTree(object):

    class Node:

        def __init__(self, start=0, end=0, left=None, right=None):
            self.start = start
            self.end = end
            self.left = left
            self.right = right
            self.is_covered = False

    def __init__(self, start, end):
        self.root = SegmentTree.Node(start, end)
        self.__generate_leaves(self.root)

    def __generate_leaves(self, root):
        if root.end - root.start == 1:
            root.left = SegmentTree.Node(root.start, root.start)
            root.right = SegmentTree.Node(root.end, root.end)
            return
        elif root.end - root.start == 0:
            return
        mid = (root.end + root.start) // 2
        root.left = SegmentTree.Node(root.start, mid)
        self.__generate_leaves(root.left)
        root.right = SegmentTree.Node(mid, root.end)
        self.__generate_leaves(root.right)

    def add_interval(self, start, end):
        self.__add_interval(self.root, start, end)

    def __add_interval(self, root, start, end):
        if root.start == start and root.end == end:
            if not root.is_covered:
                root.is_covered = True
        else:
            m = (root.start + root.end) // 2
            if end <= m:
                self.__add_interval(root.left, start, end)
            elif start >= m:
                self.__add_interval(root.right, start, end)
            else:
                self.__add_interval(root.left, start, m)
                self.__add_interval(root.right, m, end)

        if root.left is not None and root.left.is_covered \
                and root.right is not None and root.right.is_covered \
                and root.left.end == root.right.start:
            root.is_covered = True

    def get_intervals(self):
        itvls = []
        self.__get_intervals(itvls, self.root)
        return itvls

    def __get_intervals(self, itvls, root):
        if root.is_covered:
            if not itvls:
                itvls.append(Interval(root.start, root.end))
            else:
                last = itvls[-1]
                if last.end == root.start:
                    last.end = root.end
                else:
                    itvls.append(Interval(root.start, root.end))
        else:
            if root.left is not None:
                self.__get_intervals(itvls, root.left)
            if root.right is not None:
                self.__get_intervals(itvls, root.right)


class Solution:

    def merge(self, intervals):
        '''
        Merge Intervals.

        :param intervals: a list of Interval
        :type intervals: list
        :return: a list of Interval
        :rtype: list

        '''
        if not intervals:
            return []
        min = intervals[0].start
        max = intervals[0].end
        for itvl in intervals[1:]:
            if min > itvl.start:
                min = itvl.start
            if max < itvl.end:
                max = itvl.end

        segm_tree = SegmentTree(min, max)
        for itvl in intervals:
            segm_tree.add_interval(itvl.start, itvl.end)

        return segm_tree.get_intervals()


if __name__ == '__main__':
    s = Solution()
    ret = s.merge([Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)])
    print(ret)
    ret = s.merge([Interval(1, 4), Interval(0, 0)])
    print(ret)
    ret = s.merge([Interval(4, 5), Interval(2, 4), Interval(4, 6), Interval(3, 4),
                  Interval(0, 0), Interval(1, 1), Interval(3, 5), Interval(2, 2)])
    print(ret)
