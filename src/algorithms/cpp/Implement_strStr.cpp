#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
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
    int strStr(string haystack, string needle) {
        vector <int> next(SZ(needle), -1);
        for (int i = 1; i < SZ(needle); ++ i) {
            int k = next[i - 1];
            while (k != -1 && needle[k] != needle[i - 1]) {
                k = next[k];
            }
            next[i] = k + 1;
        }
        int i = 0, j = 0;
        while (i < SZ(haystack) && j < SZ(needle)) {
            if (haystack[i] == needle[j]) {
                ++ i, ++ j;
            }
            else {
                j = next[j];
                if (j == -1) {
                    j = 0, ++ i;
                }
            }
        }
        if (j == SZ(needle)) {
            return i - j;
        }
        else {
            return -1;
        }
    }
};

int main() {
    return 0;
}
