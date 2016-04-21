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
    bool isSelfCrossing(vector<int>& x) {
        if (SZ(x) <= 3)     return false;
        int i = 2;
        while (i < SZ(x) && x[i] > x[i - 2])    ++ i;
        if (i >= SZ(x))     return false;
        if ((i >= 4 && x[i] >= x[i - 2] - x[i - 4]) || (i == 3 && x[i] == x[i - 2]))
            x[i - 1] -= x[i - 3];
        ++ i;
        while (i < SZ(x)) {
            if (x[i] >= x[i - 2])   return true;
            ++ i;
        }
        return false;
    }
};


int main() {
    return 0;
}
