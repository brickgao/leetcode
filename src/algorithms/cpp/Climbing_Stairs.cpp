#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int climbStairs(int n) {
        int dp[200] = {0};
        dp[0] = 1;
        for (int i = 1; i <= n; ++ i) {
            if (i >= 1) dp[i] += dp[i - 1];
            if (i >= 2) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(2) << endl;
    return 0;
}
