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
typedef long long LL;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
     LL countDigitOne(LL n) {
        if (n <= 0LL)     return 0LL;
        LL result = 0LL, now = 1LL;
        while (now <= n) {
            LL factor = n / (now * 10LL), remainder = n % (now * 10LL);
            result += factor * now;
            result += min(now, max(remainder - now + 1LL, 0LL));
            now *= 10LL;
        }
        return result;
    }
};

int main() {
    return 0;
}
