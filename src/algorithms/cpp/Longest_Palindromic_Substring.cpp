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
    string longestPalindrome(string s) {
        if (SZ(s) <= 1) {
            return s;
        }
        int maxn = 0, rec_l = 0, rec_r = 0;
        for (int i = 0; i < SZ(s); ++ i) {
            int l = i, r = i + 1;
            while (l >= 0 && r < SZ(s) && s[l] == s[r]) {
                l -= 1, r += 1;
            }
            if (r - l - 1 > maxn) {
                maxn = r - l - 1;
                rec_l = l + 1, rec_r = r;
            }
            l = i, r = i;
            while (l >= 0 && r < SZ(s) && s[l] == s[r]) {
                l -= 1, r += 1;
            }
            if (r - l - 1 > maxn) {
                maxn = r - l - 1;
                rec_l = l + 1, rec_r = r;
            }
        }
        return s.substr(rec_l, maxn);
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.longestPalindrome("xxxabaxmm") << endl;
    return 0;
}
