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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int calculateMinimumHP(vector<vector <int> >& dungeon) {
        if (SZ(dungeon) == 0)   return 0;
        int m = SZ(dungeon), n = SZ(dungeon[0]);
        vector <vector <int> > dp;
        vector <int> v(n, 0xffff);
        for (int i = 0; i < m; ++ i)
            dp.push_back(v);
        dp[m - 1][n - 1] = max(- dungeon[m - 1][n - 1], 0);
        for (int i = m - 1; i >= 0; -- i)
            for (int j = n - 1; j >= 0; -- j) {
                if (i < m - 1)
                    dp[i][j] = min(dp[i][j], max(0, dp[i + 1][j] - dungeon[i][j]));
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j], max(0, dp[i][j + 1] - dungeon[i][j]));
            }
        return dp[0][0] + 1;
    }
};

int main() {
    vector <vector <int> > v = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
//    vector <vector <int> > v = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    Solution solution = Solution();
    cout << solution.calculateMinimumHP(v) << endl;
    return 0;
}
