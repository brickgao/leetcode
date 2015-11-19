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
    string shortestPalindrome(string s) {
        if (s == "")    return "";
        vector <int> next (SZ(s), -1);
        for (int i = 1; i < SZ(s); ++ i) {
            int k = next[i - 1];
            while (k != -1 && s[k] != s[i - 1])
                k = next[k];
            next[i] = k + 1;
        }
        int i = 0, j = SZ(s) - 1;
        while (i < SZ(s) && j > i) {
            if (i == -1 || s[i] == s[j])
                i += 1, j -= 1;
            else
                i = next[i];
        }
        string tmp_s = s.substr(0, i * 2 + 1), r_tmp_s = tmp_s;
        reverse(r_tmp_s.begin(), r_tmp_s.end());
        cout << tmp_s << endl;
        if (tmp_s == r_tmp_s)   return string(s.rbegin(), s.rend() - i * 2 - 1) + s;
        else                    return string(s.rbegin(), s.rend() - i * 2) + s;
    }
};

int main() {
    Solution solution;
    cout << solution.shortestPalindrome("aabba") << endl;
    return 0;
}
