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
    int n;
    vector <string> now;
    vector <vector <string> > result;
    bool x_flag[20], y_flag[20];
    bool diagonal_r[20], diagonal_l[20];

private:
    bool is_valid(int x, int y) {
        if (diagonal_l[n - 1 + x - y])          return false;
        if (diagonal_r[2 * (n - 1) - x - y])    return false;
        if (x_flag[x])                          return false;
        if (y_flag[y])                          return false;
        return true;
    }

private:
    void dfs(int left, int x, int y) {
        int n_x = x, n_y = y;
        while (n_x < n && n_y < n) {
            ++ n_y;
            if (n_y >= n)    ++ n_x, n_y = 0;
            if (n_x >= n)    break;
            if (is_valid(n_x, n_y)) {
                now[n_x][n_y] = 'Q';
                x_flag[n_x] = y_flag[n_y] = true;
                diagonal_l[n - 1 + n_x - n_y] = diagonal_r[2 * (n - 1) - n_x - n_y] = true;
                if (left - 1 == 0) {
                    vector <string> tmp = now;
                    result.push_back(tmp);
                }
                else {
                    dfs(left - 1, n_x, n_y);
                }
                diagonal_l[n - 1 + n_x - n_y] = diagonal_r[2 * (n - 1) - n_x - n_y] = false;
                x_flag[n_x] = y_flag[n_y] = false;
                now[n_x][n_y] = '.';
            }
            else {
                if (x_flag[n_x])
                    ++ n_x, n_y = -1;
            }
        }
        now[x][y] = '.';
    }

public:
    vector <vector <string> > solveNQueens(int n) {
        if (n == 1) {
            vector <string> tmp;
            tmp.push_back("Q");
            vector <vector <string> > result;
            result.push_back(tmp);
            return result;
        }
        for (int i = 0; i < 20; ++ i) {
            x_flag[i] = y_flag[i] = diagonal_l[i] = diagonal_r[i] = false;
        }
        this->n = n;
        for (int i = 0; i < n; ++ i) {
            string tmp(n, '.');
            now.push_back(tmp);
        }
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j) {
                now[i][j] = 'Q';
                x_flag[i] = y_flag[j] = true;
                diagonal_l[n - 1 + i - j] = diagonal_r[2 * (n - 1) - i - j] = true;
                dfs(n - 1, i, j);
                diagonal_l[n - 1 + i - j] = diagonal_r[2 * (n - 1) - i - j] = false;
                x_flag[i] = y_flag[j] = false;
                now[i][j] = '.';
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <vector <string> > result = solution.solveNQueens(9);
    for (int i = 0; i < SZ(result); ++ i) {
        for (int j = 0; j < SZ(result[i]); ++ j) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
