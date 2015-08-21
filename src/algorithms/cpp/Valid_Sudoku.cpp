#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool tag = true;
        for (int i = 0; i < SZ(board); ++ i) {
            bool vis1[10] = {false}, vis2[10] = {false};
            for (int j = 0; j < SZ(board[0]); ++ j) {
                if (board[i][j] != '.' && vis1[board[i][j] - '0'])     tag = false;
                if (board[j][i] != '.' && vis2[board[j][i] - '0'])     tag = false;
                if (board[i][j] != '.')                                vis1[board[i][j] - '0'] = true;
                if (board[j][i] != '.')                                vis2[board[j][i] - '0'] = true;
            }
        }
        for (int i = 0; i < SZ(board); i += 3) {
            for (int j = 0; j < SZ(board[0]); j += 3) {
                bool vis[10] = {false};
                for (int x = i; x < i + 3; ++ x) {
                    for (int y = j; y < j + 3; ++ y) {
                        if (board[x][y] != '.' && vis[board[x][y] - '0'])     tag = false;
                        if (board[x][y] != '.')                               vis[board[x][y] - '0'] = true;
                    }
                }
            }
        }
        return tag;
    }
};

int main() {
    return 0;
}
