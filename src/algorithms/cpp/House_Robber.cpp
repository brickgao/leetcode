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
    int rob(vector<int>& nums) {
        vector <pair <int, int> > dp (SZ(nums) + 1, make_pair(0, 0));
        for (int i = 0; i < SZ(nums); ++ i) {
            get_max(dp[i + 1].second, dp[i].first + nums[i]);
            get_max(dp[i + 1].first, max(dp[i].first, dp[i].second));
        }
        return max(dp[SZ(nums)].first, dp[SZ(nums)].second);
    }
};

int main() {
    return 0;
}
