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
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < SZ(s); ++ i) {
            ret *= 26;
            ret += s[i] - 'A' + 1;
        }
        return ret;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.titleToNumber("A") << endl;
    cout << solution.titleToNumber("Z") << endl;
    cout << solution.titleToNumber("AA") << endl;
    return 0;
}
