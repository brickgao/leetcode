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
    int trailingZeroes(int n) {
        long long now = 5;
        int cnt5 = 0, cnt2 = 0;
        while (now <= n) {
            cnt5 += n / now;
            now *= 5;
        }
        now = 2;
        while (now <= n) {
            cnt2 += n / now;
            now *= 2;
        }
        return min(cnt5, cnt2);
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.trailingZeroes(1808548329) << endl;
    return 0;
}
