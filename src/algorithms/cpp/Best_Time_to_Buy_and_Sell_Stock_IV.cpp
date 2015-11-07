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
    int maxProfit(int k, vector<int>& prices) {
        int length = SZ(prices);
        if (k > length / 2) {
            int ret = 0;
            for (int i = 1; i < length; ++ i) {
                if (prices[i] > prices[i - 1])
                    ret += prices[i] - prices[i - 1];
            }
            return ret;
        }
        else {
            k *= 2;
            vector <pair <int, int> > dp;
            for (int i = 0; i < k + 1; ++ i)    dp.push_back(make_pair(-0xffff, -0xffff));
            dp[0].second = 0;
            for (int i = 0; i < length; ++ i)
                for (int j = 1; j <= min(k, i + 1); ++ j) {
                    get_max(dp[j].first, dp[j - 1].second - prices[i]);
                    if (j >= 1)
                        get_max(dp[j].second, dp[j - 1].first + prices[i]);
                }
            int ret = 0;
            for (int i = 0; i < k + 1; ++ i)
                get_max(ret, max(dp[i].first, dp[i].second));
            return ret;
        }
    }
};

int main() {
    vector <int> v = {1, 2};
    Solution solution = Solution();
    cout << solution.maxProfit(1, v) << endl;
    return 0;
}
