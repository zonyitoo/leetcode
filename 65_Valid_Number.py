
class IntegerStateMachine:

    EOS = None

    class State:

        def __init__(self):
            self.next_states = dict()

    def __init__(self):
        self.state_trans = {
            0: {
                '0123456789': 2,
                ' ': 0,
                '-+': 1,
                '.': 4,
            },
            1: {
                '0123456789': 2,
                '.': 4,
            },
            2: {
                '0123456789': 2,
                'eE': 3,
                '.': 7,
                ' ': 5,
                (IntegerStateMachine.EOS, ): 6,
            },
            3: {
                '0123456789': 8,
                '+-': 9,
            },
            4: {
                '0123456789': 7,
            },
            5: {
                ' ': 5,
                (IntegerStateMachine.EOS, ): 6,
            },
            7: {
                '0123456789': 7,
                ' ': 5,
                (IntegerStateMachine.EOS, ): 6,
                'eE': 3,
            },
            8: {
                '0123456789': 8,
                ' ': 5,
                (IntegerStateMachine.EOS, ): 6,
            },
            9: {
                '0123456789': 8,
            }
        }
        self.__generate()

    def __generate(self):
        states = dict()
        for s, t in self.state_trans.items():
            if s not in states:
                states[s] = IntegerStateMachine.State()
            for condition, to_state in t.items():
                if to_state not in states:
                    states[to_state] = IntegerStateMachine.State()
                for c in condition:
                    states[s].next_states[c] = states[to_state]
        self.begin_state = states[0]

    def validate(self, s):
        curstat = self.begin_state
        for c in s:
            if c not in curstat.next_states:
                return False
            curstat = curstat.next_states[c]
        return IntegerStateMachine.EOS in curstat.next_states


class Solution:

    def __init__(self):
        self.ism = IntegerStateMachine()

    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        return self.ism.validate(s)


if __name__ == '__main__':
    s = Solution()
    assert s.isNumber('0') is True
    assert s.isNumber(' 0.1 ') is True
    assert s.isNumber('abc') is False
    assert s.isNumber('1 a') is False
    assert s.isNumber('2e10') is True
    assert s.isNumber('1 ') is True
    assert s.isNumber('.1') is True
    assert s.isNumber('.') is False
    assert s.isNumber('0e ') is False
    assert s.isNumber('3.') is True
    assert s.isNumber('+.8') is True
    assert s.isNumber('46.e3') is True
    assert s.isNumber('.e3') is False
    assert s.isNumber(' 005047e+6') is True
