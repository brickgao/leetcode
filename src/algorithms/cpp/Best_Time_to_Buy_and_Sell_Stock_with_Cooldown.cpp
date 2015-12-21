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
    int maxProfit(vector<int>& prices) {
        if (SZ(prices) <= 1)    return 0;
        vector <pair<int, int>> dp(SZ(prices), make_pair(0, 0));
        dp[0] = make_pair(- prices[0], 0);
        dp[1] = make_pair(max(- prices[0], - prices[1]), max(0, prices[1] - prices[0]));
        for (int i = 2; i < SZ(prices); ++ i) {
            dp[i].first = max(dp[i - 1].first, dp[i - 2].second - prices[i]);
            dp[i].second = max(dp[i - 1].second, dp[i - 1].first + prices[i]);
        }
        return dp[SZ(prices) - 1].second;
    }
};

int main() {
    return 0;
}
