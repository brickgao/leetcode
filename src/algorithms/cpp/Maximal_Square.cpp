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
    int maximalSquare(vector<vector<char>>& matrix) {
        if (SZ(matrix) == 0)    return 0;
        int m = SZ(matrix), n = SZ(matrix[0]);
        vector <vector<int>> dp;
        vector <int> tmp;
        for (int i = 0; i < n; ++ i)    tmp.push_back(0);
        for (int i = 0; i < m; ++ i)    dp.push_back(tmp);
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (matrix[i][j] == '1')
                    dp[i][j] = 1;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (i > 0 && j > 0 && dp[i - 1][j] > 0 && dp[i][j - 1] > 0 && matrix[i][j] == '1') {
                    int tmp = min(dp[i - 1][j], dp[i][j - 1]);
                    if (matrix[i - tmp][j - tmp] == '1')
                        get_max(dp[i][j], tmp + 1);
                    else
                        get_max(dp[i][j], tmp);

                }
        int result = 0;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                get_max(result, dp[i][j]);
        return result * result;
    }
};

int main() {
    return 0;
}
