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
    int numDistinct(string s, string t) {
        vector <vector <int> > dp;
        vector <int> tmp (SZ(t) + 1, 0);
        for (int i = 0; i <= SZ(s); ++ i)
            dp.push_back(tmp);
        for (int i = 0; i <= SZ(s); ++ i)
            dp[i][0] = 1;
        for (int i = 1; i <= SZ(t); ++ i)
            for (int j = i; j <= SZ(s); ++ j) {
                dp[j][i] = dp[j - 1][i];
                if (s[j - 1] == t[i - 1])
                    dp[j][i] += dp[j - 1][i - 1];
            }
        return dp[SZ(s)][SZ(t)];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
