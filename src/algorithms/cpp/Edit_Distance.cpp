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
public:
    int minDistance(string word1, string word2) {
        if (SZ(word1) == 0 || SZ(word2) == 0)
            return max(SZ(word1), SZ(word2));
        int dp[600][600] = {};
        for (int i = 0; i <= SZ(word1); ++ i)
            dp[i][0] = i;
        for (int i = 0; i <= SZ(word2); ++ i)
            dp[0][i] = i;
        for (int i = 0; i < SZ(word1); ++ i)
            for (int j = 0; j < SZ(word2); ++ j)
                if (word1[i] == word2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else
                    dp[i + 1][j + 1] = min(dp[i + 1][j],
                                           min(dp[i][j + 1],
                                               dp[i][j])) + 1;
        return dp[SZ(word1)][SZ(word2)];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.minDistance("sea", "eat") << endl;
    return 0;
}
