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
    map <char, TrieNode*> nxts;
    
public:
    // Initialize your data structure here.
    TrieNode(char _ch) : ch(_ch), is_end(false), nxts({}) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode(' ');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        int now = 0;
        while (node->nxts.count(word[now]) > 0) {
            node = node->nxts[word[now]];
            ++ now;
        }
        while (now < SZ(word)) {
            TrieNode *new_node = new TrieNode(word[now]);
            node->nxts[word[now]] = new_node;
            node = new_node;
            ++ now;
        }
        node->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        int now = 0;
        while (now < SZ(word) && node->nxts.count(word[now]) > 0) {
            node = node->nxts[word[now]];
            ++ now;
        } 
        if (now >= SZ(word))    return node->is_end;
        else                    return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int now = 0;
        while (now < SZ(prefix) && node->nxts.count(prefix[now]) > 0) {
            node = node->nxts[prefix[now]];
            ++ now;
        } 
        if (now >= SZ(prefix))    return true;
        else                      return false;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
int main() {
    Trie trie;
    trie.insert("somestring");
    cout << boolalpha << trie.search("key") << endl;
    trie.insert("key");
    cout << trie.search("key") << endl;
    cout << trie.startsWith("some") << endl;
    return 0;
}
