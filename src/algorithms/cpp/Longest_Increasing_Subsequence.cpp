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
    int lengthOfLIS(vector<int>& nums) {
        vector <int> dp (SZ(nums), 1);
        for (int i = 0; i < SZ(nums); ++ i) {
            for (int j = 0; j < i; ++ j) {
                if (nums[j] < nums[i])
                    get_max(dp[i], dp[j] + 1);
            }
        }
        int maxn = 0;
        for (int i = 0; i < SZ(nums); ++ i) {
            get_max(maxn, dp[i]);
        }
        return maxn;
    }
};

int main() {
    return 0;
}
