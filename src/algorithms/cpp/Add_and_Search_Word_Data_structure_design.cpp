#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


class TrieNode {
public:
    char ch;
    bool is_end;
    TrieNode *nxts[26];
    
public:
    TrieNode(char _ch) : ch(_ch), is_end(false) {
        for (int i = 0; i < 26; ++ i)   this->nxts[i] = NULL;
    }
};


class Trie {
public:
    Trie() : root(new TrieNode(' ')) {}

    void insert(string word) {
        TrieNode *node = root;
        int now = 0;
        while (now < SZ(word) && node->nxts[word[now] - 'a'] != NULL) {
            node = node->nxts[word[now] - 'a'];
            ++ now;
        }
        while (now < SZ(word)) {
            TrieNode *new_node = new TrieNode(word[now]);
            node->nxts[word[now] - 'a'] = new_node;
            node = new_node;
            ++ now;
        }
        node->is_end = true;
    }

    bool search(string &word) {
        return this->dosearch(root, word, 0);
    }

private:
    bool dosearch(TrieNode *node, string &word, int now) {
        if (now >= SZ(word))    return node->is_end;
        if (word[now] == '.') {
            bool tag = false;
            for (int i = 0; i < 26; ++ i) {
                if (node->nxts[i] != NULL)
                    tag |= this->dosearch(node->nxts[i], word, now + 1);
            }
            return tag;
        }
        else {
            if (node->nxts[word[now] - 'a'] != NULL)
                return this->dosearch(node->nxts[word[now] - 'a'], word, now + 1);
            else
                return false;
        }
    }

private:
    TrieNode* root;
};


class WordDictionary {
private:
    Trie trie;
    
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.search(word);
    }
};


// Your WordDictionary object will be instantiated and called as such:
int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    wordDictionary.addWord("wxrd");
    wordDictionary.addWord("ssd");
    wordDictionary.addWord("sd");
    cout << boolalpha;
    cout << wordDictionary.search(".") << endl;
    cout << wordDictionary.search("woxxd") << endl;
    cout << wordDictionary.search("word") << endl;
    cout << wordDictionary.search("w.rd") << endl;
    cout << wordDictionary.search("wx.d") << endl;
    cout << wordDictionary.search("ss.") << endl;
    return 0;
}
