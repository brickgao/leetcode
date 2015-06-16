# -*- coding: utf-8 -*-


class LRUCache:
    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.l = []
        self.d = {}

    # @return an integer
    def get(self, key):
        if key in self.d:
            pos = self.l.index(key)
            self.l = [key] + self.l[:pos] + self.l[pos + 1:]
            return self.d[key]
        else:
            return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.d:
            pos = self.l.index(key)
            self.l = [key] + self.l[:pos] + self.l[pos + 1:]
        else:
            if len(self.l) == self.capacity:
                del self.d[self.l[-1]]
                self.l = [key] + self.l[:-1]
            else:
                self.l = [key] + self.l
        self.d[key] = value


if __name__ == "__main__":
    lrucahe = LRUCache(2)
    lrucahe.set(2, 1)
    print lrucahe.l, lrucahe.d
    lrucahe.set(2, 2)
    print lrucahe.l, lrucahe.d
    print lrucahe.get(2)
    print lrucahe.l, lrucahe.d
    lrucahe.set(1, 1)
    print lrucahe.l, lrucahe.d
    lrucahe.set(4, 1)
    print lrucahe.l, lrucahe.d
    print lrucahe.get(2)
    print lrucahe.l, lrucahe.d
