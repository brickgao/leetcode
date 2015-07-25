# -*- coding: utf-8 -*-


class Queue:
    # initialize your data structure here.
    def __init__(self):
        self.st = []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.st.append(x)

    # @return nothing
    def pop(self):
        _st = []
        while len(self.st) > 1:
            _st.append(self.st.pop())
        self.st = []
        while _st != []:
            self.st.append(_st.pop())

    # @return an integer
    def peek(self):
        _st = []
        while len(self.st) > 1:
            _st.append(self.st.pop())
        ret = self.st[-1]
        _st.append(self.st.pop())
        while _st != []:
            self.st.append(_st.pop())
        return ret

    # @return an boolean
    def empty(self):
        return self.st == []


if __name__ == "__main__":
    queue = Queue()
    print queue.empty()
    queue.push(1)
    queue.push(2)
    print queue.peek()
    queue.pop()
    print queue.peek()
    print queue.empty()
