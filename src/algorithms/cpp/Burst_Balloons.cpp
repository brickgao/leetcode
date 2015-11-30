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
typedef long long LL;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int maxCoins(vector<int>& _nums) {
        vector <int> nums = {1};
        for (auto &num: _nums)
            if (num > 0)    nums.push_back(num);
        nums.push_back(1);
        int n = SZ(nums);
        vector <vector <int>> dp (n, vector <int> (n, 0));
        for (int i = 0; i < n - 2; ++ i)
            dp[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2];
        for (int i = 4; i <= n; ++ i)
            for (int j = 0; j < n - i + 1; ++ j) {
                int beg = j, end = j + i - 1;
                int beg_mul_end = nums[beg] * nums[end];
                int _tmp = dp[beg][end - 1] + beg_mul_end * nums[end - 1];
                if (_tmp > dp[beg][end])    dp[beg][end] = _tmp;
                _tmp = dp[beg + 1][end] + beg_mul_end * nums[beg + 1];
                if (_tmp > dp[beg][end])    dp[beg][end] = _tmp;
                for (int k = beg + 2; k < end - 2 + 1; ++ k) {
                    _tmp = dp[beg][k] + dp[k][end] + beg_mul_end * nums[k];
                    if (_tmp > dp[beg][end])    dp[beg][end] = _tmp;
                }
            }
        return dp[0][n - 1];
    }
};

int main() {
    return 0;
}
