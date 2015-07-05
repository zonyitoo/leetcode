class Solution:

    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        ind, last, count = 0, None, 0
        while ind < len(A):
            if last == A[ind]:
                count += 1

                if count >= 3:
                    A.pop(ind)
                else:
                    ind += 1
            else:
                last, count = A[ind], 1
                ind += 1
        return len(A)
