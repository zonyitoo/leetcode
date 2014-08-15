class Solution:

    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        if len(A) <= 2:
            return 0
        lmax = [0 for _ in A]
        rmax = [0 for _ in A]
        lmax[0], rmax[-1] = A[0], A[-1]
        for i in range(1, len(A) - 1):
            lmax[i] = lmax[i - 1] if lmax[i - 1] > A[i] else A[i]
            rmax[-i - 1] = rmax[-i] if rmax[-i] > A[-i - 1] else A[-i - 1]
        water = 0
        for idx, high in enumerate(A):
            if lmax[idx] > high and rmax[idx] > high:
                water += min(lmax[idx], rmax[idx]) - high
        return water
