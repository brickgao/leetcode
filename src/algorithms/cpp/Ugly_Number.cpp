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
    bool isUgly(int n) {
        if (n == 0)             return false;
        while (n % 2 == 0)      n /= 2;
        while (n % 3 == 0)      n /= 3;
        while (n % 5 == 0)      n /= 5;
        return n == 1;
    }
};

int main() {
    return 0;
}
