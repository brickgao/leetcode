#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
typedef long long LL;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    bool isPowerOfThree(int n) {
        int max_3_power_int = 1162261467;
        if (n <= 0 || n > max_3_power_int)  return false;
        return max_3_power_int % n == 0;
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.isPowerOfThree(3) << endl;
    cout << solution.isPowerOfThree(6) << endl;
    cout << solution.isPowerOfThree(9) << endl;
    return 0;
}
