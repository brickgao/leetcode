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
    vector <vector <int> > mp;
    int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

private:
    void dfs(vector <vector <char> > &grid, int x, int y, int cnt) {
        for (int i = 0; i < 4; ++ i) {
            int nx = x + mv[i][0], ny = y + mv[i][1];
            if (nx >= SZ(grid) || nx < 0)      continue;
            if (ny >= SZ(grid[0]) || ny < 0)   continue;
            if (grid[nx][ny] != '0' && mp[nx][ny] == -1) {
                mp[nx][ny] = cnt;
                dfs(grid, nx, ny, cnt);
            }
        }
    }

public:
    int numIslands(vector <vector <char> > &grid) {
        if (SZ(grid) == 0)      return 0;
        vector <int> v (SZ(grid[0]), -1);
        for (int i = 0; i < SZ(grid); ++ i)
            mp.push_back(v);
        int result = 0;
        int m = SZ(grid), n = SZ(grid[0]);
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (grid[i][j] == '1' && mp[i][j] == -1) {
                    mp[i][j] = ++ result;
                    dfs(grid, i, j, result);
                }
        return result;
    }
};

int main() {
    vector <vector <char> > input = {{'1', '1', '0', '0', '0'},
                                     {'1', '1', '0', '0', '0'},
                                     {'0', '0', '1', '0', '0'},
                                     {'0', '0', '0', '1', '1'}};
    Solution solution = Solution();
    cout << solution.numIslands(input) << endl;
    return 0;
}
