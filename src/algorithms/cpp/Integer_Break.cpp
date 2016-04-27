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
    int integerBreak(int n) {
        vector <int> dp = {0, 0, 1, 2, 4, 6, 9};
        while (SZ(dp) <= n)
            dp.push_back(dp[SZ(dp) - 3] * 3);
        return dp[n];
    }
};


int main() {
    Solution solution;
    solution.integerBreak(20);
    return 0;
}
