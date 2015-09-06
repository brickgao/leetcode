#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, mid;
        while (l < r - 1) {
            mid = (l + r) >> 1;
            int tmp = x / mid;
            if (tmp == mid)
                return mid;
            else if (tmp > mid)
                l = mid;
            else
                r = mid;
        }
        if (r * r == x)
            return r;
        else
            return l;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.mySqrt(1) << endl;
    cout << solution.mySqrt(3) << endl;
    cout << solution.mySqrt(2147395599) << endl;
    return 0;
}
