class Solution:
    # @param s, a string
    # @return a string

    def reverseWords(self, s):
        striped = s.strip()
        words = striped.split(' ')
        words.reverse()
        words = [w for w in words if w != '']
        return ' '.join(words)
