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

int dp[10000];
bool is_p[10000][10000];

class Solution {
public:
    int minCut(string s) {
        dp[SZ(s)] = 0;
        for (int i = 0; i < SZ(s); ++ i)    dp[i] = SZ(s);
        for (int i = 0; i < SZ(s); ++ i)
            for (int j = 0; j < SZ(s); ++ j)
                is_p[i][j] = false;
        for (int i = 0; i < SZ(s); ++ i)
            for (int j = i; j >= 0; -- j) {
                if (i - j + 1 == 1)
                    is_p[j][i] = true;
                else if (i - j + 1 == 2)
                    is_p[j][i] = (s[i] == s[j]);
                else
                    is_p[j][i] = is_p[j + 1][i - 1] && (s[i] == s[j]);
            }
        for (int i = SZ(s) - 1; i >= 0; -- i) {
            for (int j = i; j < SZ(s); ++ j) {
                if (is_p[i][j])
                    get_min(dp[i], dp[j + 1] + 1);
            }
        }
        return dp[0] - 1;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.minCut("aab") << endl;
    cout << solution.minCut("ababababababababababababcbabababababababababababa") << endl;
    return 0;
}
