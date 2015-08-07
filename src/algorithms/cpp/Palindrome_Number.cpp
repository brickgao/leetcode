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
    bool isPalindrome(int x) {
        if (x < 0)      return false;
        if (x == 0)     return true;
        int div1 = 10, div2 = 1000000000, tmp = x;
        while (tmp / div2 == 0)  div2 /= 10;
        while (div1 <= div2) {
            if (x % div1 != tmp / div2) return false;
            x /= 10;
            tmp %= div2;
            div2 /= 10;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isPalindrome(10) << endl;
    cout << solution.isPalindrome(12321) << endl;
    cout << solution.isPalindrome(1211) << endl;
    return 0;
}
