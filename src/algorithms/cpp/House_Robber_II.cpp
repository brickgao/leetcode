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
        vector <pair<int, int>> dp1(SZ(nums), make_pair(0, 0)), dp2(SZ(nums), make_pair(0, 0));
        if (SZ(nums) == 0)  return 0;
        dp1[0].second = nums[0];
        for (int i = 1; i < SZ(nums); ++ i) {
            get_max(dp1[i].first, max(dp1[i - 1].first, dp1[i - 1].second));
            if (i != SZ(nums) - 1)
                get_max(dp1[i].second, dp1[i - 1].first + nums[i]);
        }
        for (int i = 1; i < SZ(nums); ++ i) {
            get_max(dp2[i].first, max(dp2[i - 1].first, dp2[i - 1].second));
            get_max(dp2[i].second, dp2[i - 1].first + nums[i]);
        }
        return max(
            max(dp1[SZ(nums) - 1].first, dp1[SZ(nums) - 1].second),
            max(dp2[SZ(nums) - 1].first, dp2[SZ(nums) - 1].second)
        );
    }
};

int main() {
    return 0;
}
