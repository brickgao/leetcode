#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
const double eps = 1e-6;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    vector <vector <char> > board;
    bool vis[200][200];
    string word;
    int move[4][2];
    int m, n;

private:
    inline bool is_valid(const int &x, const int &y) {
        if (x < 0 || x >= m)    return false;
        if (y < 0 || y >= n)    return false;
        return true;
    }

private:
    bool search(const int &x, const int &y, int now) {
        if (word[now] == board[x][y]) {
            if (now == SZ(word) - 1)
                return true;
            bool ret = false;
            for (int i = 0; i < 4; ++ i) {
                int new_x = x + move[i][0], new_y = y + move[i][1];
                if (is_valid(new_x, new_y) && !vis[new_x][new_y]) {
                    vis[new_x][new_y] = true;
                    ret = ret || search(new_x, new_y, now + 1);
                    vis[new_x][new_y] = false;
                    if (ret)    return ret;
                }
            }
            return ret;
        }
        else 
            return false;
    }

public:
    bool exist(vector<vector <char> >& board, string word) {
        move[0][0] = 0, move[0][1] = 1;
        move[1][0] = 0, move[1][1] = -1;
        move[2][0] = 1, move[2][1] = 0;
        move[3][0] = -1, move[3][1] = 0;
        if (SZ(board) == 0) {
            if (word == "") return true;
            else            return false;
        }
        m = SZ(board), n = SZ(board[0]);
        this->word = word;
        this->board = board;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                vis[i][j] = false;
        bool ret = false;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                vis[i][j] = true;
                ret = ret || search(i, j, 0);
                vis[i][j] = false;
                if (ret)    return ret;
            }
        }
        return ret;
    }
};

int main() {
    vector <vector <char> > input_mat = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution solution = Solution();
    cout << solution.exist(input_mat, "ABCCED") << endl;
    cout << solution.exist(input_mat, "SEE") << endl;
    cout << solution.exist(input_mat, "ABCB") << endl;
    return 0;
}
