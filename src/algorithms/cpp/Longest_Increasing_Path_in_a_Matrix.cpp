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
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    vector <vector<int>> rec, matrix;
    map <pair<int, int>, int> path;
    

    void dfs(int step, int x, int y) {
        rec[x][y] = step;
        for (int i = 0; i < 4; ++ i) {
            int nx = x + moves[i][0], ny = y + moves[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y] && step + 1 > rec[nx][ny]) {
                dfs(step + 1, nx, ny);
            }
        }
    }


public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (SZ(matrix) == 0)    return 0;
        this->matrix = matrix;
        m = SZ(matrix), n = SZ(matrix[0]);
        for (int i = 0; i < m; ++ i) {
            vector <int> tmp(n, 0);
            rec.push_back(tmp);
        }
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (rec[i][j] == 0)
                    dfs(1, i, j);
        int result = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                get_max(result, rec[i][j]);
            }
        }
        return result;
    }
};


int main() {
    Solution solution;
    vector <vector<int>> mp = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    cout << solution.longestIncreasingPath(mp) << endl;
    return 0;
}
