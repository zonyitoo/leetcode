class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer

    def searchInsert(self, A, target):
        if len(A) == 0:
            return 0
        return self.binarySearch(A, target, 0, len(A) - 1)

    def binarySearch(self, A, target, beg, end):
        if beg == end:
            if A[beg] == target:
                return beg
            else:
                return beg if target < A[beg] else beg + 1
        mid = (beg + end) // 2
        if A[mid] == target:
            return mid
        if target < A[mid]:
            return self.binarySearch(A, target, beg, mid)
        else:
            return self.binarySearch(A, target, mid + 1, end)
