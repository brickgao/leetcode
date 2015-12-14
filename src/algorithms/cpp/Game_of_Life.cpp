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

class Solution {
private:
    int diffs[8][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
        {-1, -1},
        {1, 1},
        {1, -1},
        {-1, 1}
    };

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = SZ(board), n = SZ(board[0]);
        vector <vector<int>> new_board (m, vector <int> (n, 0));
        for (int x = 0; x < m; ++ x) {
            for (int y = 0; y < n; ++ y) {
                int cnt = 0;
                for (int i = 0; i < 8; ++ i) {
                    int nx = x + diffs[i][0];
                    int ny = y + diffs[i][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    cnt += board[nx][ny];
                }
                if (cnt < 2)
                    new_board[x][y] = 0;
                else if (cnt == 2)
                    new_board[x][y] = board[x][y];
                else if (cnt == 3)
                    new_board[x][y] = 1;
                else
                    new_board[x][y] = 0;
            }
        }
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                board[i][j] = new_board[i][j];
    }
};

int main() {
    return 0;
}
