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
    TrieNode(char _ch) : ch(_ch), is_end(false) {for (int i = 0; i < 26; ++ i) nxts[i] = NULL;}
};


class Solution {
private:
    int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    int maxn;
    vector <vector <bool> > vis;
    set <string> result;

private:
    void dfs(vector<vector<char>>& board, TrieNode *node, int x, int y, string &s_now) {
        string s = s_now + board[x][y];
        if (node->nxts[board[x][y] - 'a'] == NULL) {
            return;
        }
        else  {
            if (node->nxts[board[x][y] - 'a']->is_end)       result.insert(s);
        }
        if (SZ(s) >= maxn)          return;
        vis[x][y] = true;
        for (int i = 0; i < 4; ++ i) {
            int nx = x + mv[i][0], ny = y + mv[i][1];
            if (nx < 0 || ny < 0)     continue;
            if (nx >= m || ny >= n)   continue;
            if (!vis[nx][ny])   dfs(board, node->nxts[board[x][y] - 'a'], nx, ny, s);
        }
        vis[x][y] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode(' ');
        if (SZ(board) == 0)                 return vector <string> {};
        m = SZ(board), n = SZ(board[0]);
        maxn = 0;
        vector <bool> tmp_v (n, false);
        for (int i = 0; i < m; ++ i)        vis.push_back(tmp_v);
        for (auto &word: words) {
            get_max(maxn, SZ(word));
            TrieNode *node = trie;
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
        string begin_s = "";
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                dfs(board, trie, i, j, begin_s);
        vector <string> ret;
        for (auto s: result)                ret.push_back(s);
        return ret;
    }
};


int main() {
    Solution solution;
    vector <vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector <string> words = {"oath", "pea", "eat", "rain"};
    vector <string> result = solution.findWords(board, words);
    for (auto s: result)    cout << s << endl;
    return 0;
}
