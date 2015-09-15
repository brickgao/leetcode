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

bool dp[200][200][200] = {};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (SZ(s1) != SZ(s2))   return false;
        if (SZ(s1) == 0)        return true;
        for (int i = 0; i <= SZ(s1); ++ i)
            for (int j = 0; j <= SZ(s1); ++ j)
                for (int k = 0; k <= SZ(s1); ++ k)
                    dp[i][j][k] = false;
        for (int i = 0; i < SZ(s1); ++ i)
            for (int j = 0; j < SZ(s2); ++ j)
                if(s1[i] == s2[j])
                    dp[0][i][j] = true;
        for (int k = 2; k <= SZ(s1); ++ k)
            for (int i = SZ(s1) - k; i >= 0; -- i)
                for (int j = SZ(s1) - k; j >= 0; -- j) {
                    bool tag = false;
                    for (int m = 1; m < k; ++ m) {
                        tag = (dp[m - 1][i][j] && dp[k - m - 1][i + m][j + m]) || (dp[m - 1][i][j + k - m] && dp[k - m - 1][i + m][j]);
                        if (tag)    break;
                    }
                    dp[k - 1][i][j] = tag;
                }
        return dp[SZ(s1) - 1][0][0];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isScramble("a", "b") << endl;
    return 0;
}
