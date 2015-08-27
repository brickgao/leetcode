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
    bool isMatch(string s, string p) {
        int dp[2][4500];
        int pos = 0;
        for (int i = 0; i < 2; ++ i)
            for (int j = 0; j <= SZ(p); ++ j)
                dp[i][j] = false;
        dp[SZ(s) % 2][SZ(p)] = true;
        if (p[SZ(p) - 1] == '*')   dp[SZ(s) % 2][SZ(p) - 1] = true;
        for (int i = SZ(s) - 1; i >= 0; -- i) {
            int now = i % 2, pre = (i + 1) % 2;
            for (int j = 0; j <= SZ(p); ++ j)
                dp[now][j] = false;
            for (int j = SZ(p) - 1; j >= 0; -- j) {
                if (p[j] == '*' && dp[pre][j])
                    dp[now][j] = true;
                if (p[j] == '*' && dp[pre][j + 1])
                    dp[now][j] = true, dp[pre][j] = true;
                if (p[j] == '?' && dp[pre][j + 1])
                    dp[now][j] = true;
                if (p[j] == s[i] && dp[pre][j + 1])
                    dp[now][j] = true;
            }
        }
        for (int j = SZ(p) - 1; j >= 0; -- j)
            if (p[j] == '*' && dp[0][j + 1])
                dp[0][j] = true;
        return dp[0][0];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "aa") << endl;
    cout << solution.isMatch("aa", "*") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("ab", "?*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    cout << solution.isMatch("ab", "ab*") << endl;
    cout << solution.isMatch("c", "*?*") << endl;
    cout << solution.isMatch("ab", "ab**") << endl;
    cout << solution.isMatch("abcdefde", "abc*def") << endl;
    return 0;
}
