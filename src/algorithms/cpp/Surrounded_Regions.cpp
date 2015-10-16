#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int vis[500][500];

class Solution {
private:
    vector <vector <char> > board;
    int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    inline bool is_valid(int x, int y) {
        if (x < 0 || x >= m)  return false;
        if (y < 0 || y >= n)  return false;
        return true;
    }

    bool bfs(int x, int y, int tag) {
        bool ret = true;
        queue <pair <int, int> > q;
        q.push(make_pair(x, y));
        vis[x][y] = tag;
        while (!q.empty()) {
            pair <int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 4; ++ i) {
                int nx = front.first + mv[i][0];
                int ny = front.second + mv[i][1];
                if (is_valid(nx, ny)) {
                    if (board[nx][ny] == 'O' && vis[nx][ny] == 0) {
                        vis[nx][ny] = tag;
                        q.push(make_pair(nx, ny));
                    }
                }
                else
                    ret = false;
            }
        }
        return ret;
    }

public:
    void solve(vector<vector <char> > &board) {
        if (SZ(board) == 0) return;
        this->board = board;
        m = SZ(board), n = SZ(board[0]);
        int cnt = 0;
        set <int> g_set;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                vis[i][j] = 0;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    ++ cnt;
                    if (bfs(i, j, cnt))  g_set.insert(cnt);
                }
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (g_set.count(vis[i][j]) != 0)
                    board[i][j] = 'X';
    }
};

int main() {
    vector <string> tmp = {"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO","OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO","OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO","OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO","OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO","OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"};
    vector <vector <char> > board;
    for (auto s: tmp) {
        vector <char> v;
        for (auto ch: s)
            v.push_back(ch);
        board.push_back(v);
    }
    Solution solution = Solution();
    solution.solve(board);
    for (int i = 0; i < SZ(board); ++ i) {
        for (int j = 0; j < SZ(board[i]); ++ j)
            cout << board[i][j] << " ";
        cout << endl;
    }
                                    
    return 0;
}
