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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int MAX_INT = 2147483647;

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if (divisor == 0)
            return MAX_INT;
        long long tmp = dividend / divisor;
        if (tmp >= - MAX_INT - 1 && tmp <= MAX_INT) {
            return tmp;
        }
        else {
            return MAX_INT;
        }
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.divide(-2147483648, -1) << endl;
    return 0;
}
