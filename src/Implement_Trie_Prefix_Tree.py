# -*- coding: utf-8 -*-


class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.nxt = {}
        self.tag = False


class Trie:

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.nxt:
                node.nxt[ch] = TrieNode()
            node = node.nxt[ch]
        node.tag = True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        node = self.root
        for ch in word:
            if ch not in node.nxt:
                return False
            node = node.nxt[ch]
        return node.tag

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        node = self.root
        for ch in prefix:
            if ch not in node.nxt:
                return False
            node = node.nxt[ch]
        return True


if __name__ == "__main__":
    # Your Trie object will be instantiated and called as such:
    trie = Trie()
    trie.insert("somestring")
    print trie.search("key")
    print trie.search("somestring")
    print trie.search("somestr")
    print trie.startsWith("somestr")
