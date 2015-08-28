#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
const double eps = 1e-6;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

inline int sgn(double x) {
    if (fabs(x) < eps)  return 0;
    return x > 0 ? 1 : -1;
}

class Solution {
public:
    double myPow(double x, int n) {
        if (sgn(x - 1.0) == 0)       return x;
        if (sgn(x + 1.0) == 0) {
            if ((n % 2 + 10) % 2 == 1)      return -1.0;
            else                            return 1.0;
        }
        double tmp, result = 1.0;
        if (n >= 0) tmp = x;
        else        tmp = 1.0 / x, n = -n;
        while (n) {
            if (n & 1) {
                result *= tmp;
            }
            tmp *= tmp;
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.myPow(3.0, 3) << endl;
    cout << solution.myPow(34.00515, -3) << endl;
    return 0;
}
