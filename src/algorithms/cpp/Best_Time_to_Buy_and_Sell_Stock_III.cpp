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

int l[21000], r[21000];

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        int tmp = 0, maxn = 0;
        for (int i = 1; i < SZ(prices) - 1; ++ i) {
            tmp += prices[i] - prices[i - 1];
            get_max(tmp, 0);
            get_max(maxn, tmp);
            l[i] = maxn;
        }
        tmp = 0, maxn = 0;
        for (int i = SZ(prices) - 2; i >= 0; -- i) {
            tmp += prices[i + 1] - prices[i];
            get_max(tmp, 0);
            get_max(maxn, tmp);
            r[i] = maxn;
        }
        int result = 0;
        for (int i = 0; i < SZ(prices); ++ i) {
            get_max(result, l[i] + r[i]);
        }
        return result;
    }
};

int main() {
    return 0;
}
