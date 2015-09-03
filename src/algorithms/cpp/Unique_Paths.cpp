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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[110][110] = {0};
        for (int i = 0; i < m; ++ i)
            dp[i][0] = 1;
        for (int i = 0; i < n; ++ i)
            dp[0][i] = 1;
        for (int i = 1; i < m; ++ i)
            for (int j = 1; j < n; ++ j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.uniquePaths(3, 7) << endl;
    return 0;
}
