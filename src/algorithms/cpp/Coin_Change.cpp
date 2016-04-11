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
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount + 1, amount + 1);
        dp[amount] = 0;
        for (int i = amount; i > 0; -- i) {
            for (int &coin: coins) {
                if (i - coin >= 0)
                    get_min(dp[i - coin], dp[i] + 1);
            }
        }
        return dp[0] == amount + 1 ? -1 : dp[0];
    }
};


int main() {
    Solution solution = Solution();
    vector <int> coins = {1, 2, 5};
    cout << solution.coinChange(coins, 11) << endl;
    return 0;
}
