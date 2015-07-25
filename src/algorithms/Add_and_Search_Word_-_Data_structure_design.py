# -*- coding: utf-8 -*-


class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.nxt = {}
        self.tag = False


class WordDictionary:
    # initialize your data structure here.
    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Adds a word into the data structure.
    def addWord(self, word):
        node = self.root
        for ch in word:
            if ch not in node.nxt:
                node.nxt[ch] = TrieNode()
            node = node.nxt[ch]
        node.tag = True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the data structure. A word could
    # contain the dot character '.' to represent any one letter.
    def search(self, word):
        return self.do_search(self.root, word)

    def do_search(self, node, word):
        ret = False
        if word == "":
            return node.tag
        if word[0] == ".":
            for ch in node.nxt.keys():
                ret = ret or self.do_search(node.nxt[ch], word[1:])
            return ret
        elif word[0] in node.nxt:
            return self.do_search(node.nxt[word[0]], word[1:])
        else:
            return False


# Your WordDictionary object will be instantiated and called as such:
if __name__ == "__main__":
    wordDictionary = WordDictionary()
    wordDictionary.addWord("bad")
    wordDictionary.addWord("dad")
    wordDictionary.addWord("mad")
    print wordDictionary.search("pad")
    print wordDictionary.search("bad")
    print wordDictionary.search(".ad")
    print wordDictionary.search("b..")
    print wordDictionary.search(".")
    for x in "abcdefghijklmnopqrstuvwxyz":
        wordDictionary.addWord(x)
        for y in "abcdefghijklmnopqrstuvwxyz":
            wordDictionary.addWord(x + y)
            for z in "abcdefghijklmnopqrstuvwxyz":
                wordDictionary.addWord(x + y + z)
    for i in range(10000):
        wordDictionary.search(".")
    wordDictionary.addWord("a")
    wordDictionary.addWord("a")
    print wordDictionary.search(".")
    print wordDictionary.search("a")
    print wordDictionary.search("aa")
    print wordDictionary.search("a")
    print wordDictionary.search(".a")
    print wordDictionary.search("a.")
