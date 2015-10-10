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
    int minimumTotal(vector<vector <int> >& triangle) {
        int m = SZ(triangle), n = SZ(triangle[m - 1]);
        if (SZ(triangle) == 0)      return 0;
        int dp[10000];
        for (int i = 0; i < n; ++ i)
            dp[i] = 0XFFFFFF;
        dp[0] = triangle[0][0];
        for (int i = 1; i < SZ(triangle); ++ i) {
            for (int j = SZ(triangle[i]) - 1; j >= 0; -- j) {
                int pre1 = 0xFFFFFF, pre2 = 0xFFFFFF;
                if (j - 1 >= 0)  pre1 = dp[j - 1];
                if (j >= 0)      pre2 = dp[j];
                dp[j] = min(pre1, pre2) + triangle[i][j];
            }
        }
        int result = 0XFFFFFF;
        for (int i = 0; i < n; ++ i)
            get_min(result, dp[i]);
        return result;
    }
};

int main() {
    vector <vector <int> > input_v = {{-1}, {-2, -3}};
    Solution solution = Solution();
    cout << solution.minimumTotal(input_v) << endl;
    return 0;
}
