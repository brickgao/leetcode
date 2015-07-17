# -*- coding: utf-8 -*-

from Queue import Queue


class Stack:
    # initialize your data structure here.
    def __init__(self):
        self.queue = Queue()

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.queue.put(x)

    # @return nothing
    def pop(self):
        _tmp, _size = Queue(), self.queue.qsize()
        for i in range(_size):
            _ = self.queue.get()
            if i < _size - 1:
                _tmp.put(_)
        self.queue = _tmp

    # @return an integer
    def top(self):
        _tmp = Queue()
        for i in range(self.queue.qsize()):
            _ = self.queue.get()
            _tmp.put(_)
        self.queue = _tmp
        return _

    # @return an boolean
    def empty(self):
        return self.queue.empty()


if __name__ == "__main__":
    st = Stack()
    st.push(1)
    st.push(2)
    print st.top()
    st.pop()
    print st.top()
