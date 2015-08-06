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
    int reverse(int x) {
        int flag = 1, result = 0, mul = 1;
        if (x < 0)  flag = -1, x = -x;
        while (x) {
            int tmp = x % 10;
            result = result * 10 + tmp;
            mul *= 10, x /= 10;
            if (result < 0 || result % 10 != tmp) return 0;
        }
        return result * flag;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.reverse(711) << endl;
    cout << solution.reverse(10) << endl;
    cout << solution.reverse(1000000003) << endl;
    cout << solution.reverse(1534236469) << endl;
}
