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
    bool isPowerOfFour(int num) {
        if (num <= 0)           return false;
        if ((num & (num - 1)) == 0 && (num - 1) % 3 == 0)    return true;
        else                                                 return false;
    }
};


int main() {
    return 0;
}
