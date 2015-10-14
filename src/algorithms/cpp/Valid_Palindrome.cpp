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
    bool isPalindrome(string s) {
        string n_s = "", r_n_s = "";
        for (int i = 0; i < SZ(s); ++ i) {
            if ('a' <= s[i] && s[i] <= 'z')     n_s += s[i];
            if ('A' <= s[i] && s[i] <= 'Z')     n_s += static_cast<char>(s[i] - 'A' + 'a');
            if ('0' <= s[i] && s[i] <= '9')     n_s += s[i];
        }
        r_n_s = n_s;
        reverse(r_n_s.begin(), r_n_s.end());
        if (n_s == r_n_s)   return true;
        else                return false;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    return 0;
}
