# -*- coding: utf-8 -*-


class MinStack:
    # initialize your data structure here.
    def __init__(self):
        self.st = []
        self._min = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        self.st.append(x)
        if len(self._min):
            self._min.append(min(self._min[-1], x))
        else:
            self._min.append(x)
        return x

    # @return nothing
    def pop(self):
        self.st.pop()
        self._min.pop()

    # @return an integer
    def top(self):
        return self.st[-1]

    # @return an integer
    def getMin(self):
        return self._min[-1]

if __name__ == "__main__":
    solution = Sort_List()
