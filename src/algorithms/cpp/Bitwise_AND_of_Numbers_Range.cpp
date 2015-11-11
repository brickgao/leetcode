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
    int rangeBitwiseAnd(int m, int n) {
        int divisor = 1 << 30;
        int result = 0;
        while (divisor > 0) {
            result <<= 1;
            int cnt1 = m / divisor, cnt2 = n / divisor;
            if (cnt1 == cnt2 && (cnt1 & 1)  == 1)
                result |= 1;
            divisor >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.rangeBitwiseAnd(4, 6) << endl;
    cout << solution.rangeBitwiseAnd(1, 3) << endl;
    cout << solution.rangeBitwiseAnd(3, 3) << endl;
    return 0;
}
