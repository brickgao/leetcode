#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

bool dp[500][500] = {};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (SZ(s1) + SZ(s2) != SZ(s3))  return false;
        for (int i = 0; i <= SZ(s3); ++ i)
            for (int j = 0; j <= SZ(s1); ++ j)
                dp[i][j] = false;
        dp[0][0] = true;
        for (int i = 1; i <= SZ(s3); ++ i) {
            int upper = min(i, SZ(s1));
            for (int j = 0; j <= upper; ++ j) {
                int k = i - j;
                if (j > SZ(s1) || k > SZ(s2))
                    continue;
                if (j >= 1 && s1[j - 1] == s3[i - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] || dp[i][j]);
                }
                if (k >= 1 && s2[k - 1] == s3[i - 1]) {
                    dp[i][j] = (dp[i - 1][j] || dp[i][j]);
                }
            }
        }
        return dp[SZ(s3)][SZ(s1)];
    }
};

int main() {
    return 0;
}
