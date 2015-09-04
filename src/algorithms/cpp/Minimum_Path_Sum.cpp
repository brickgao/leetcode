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
    int minPathSum(vector <vector <int> >& grid) {
        if (SZ(grid) == 0)      return 0;
        vector <vector <int> > result;
        int m = SZ(grid), n = SZ(grid[0]);
        for (int i = 0; i < m; ++ i) {
            vector <int> tmp (n, 0);
            result.push_back(tmp);
        }
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int pre = 0xffff;
                if (i > 0)  get_min(pre, result[i - 1][j]);
                if (j > 0)  get_min(pre, result[i][j - 1]);
                if (pre == 0xffff)  pre = 0;
                result[i][j] = pre + grid[i][j];
            }
        }
        return result[m - 1][n - 1];
    }
};

int main() {
    return 0;
}
