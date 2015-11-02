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
    string fractionToDecimal(int _numerator, int _denominator) {
        bool tag = true;
        LL numerator = static_cast <LL> (_numerator);
        LL denominator = static_cast <LL> (_denominator);
        if (numerator * denominator >= 0L)    tag = true;
        else                                  tag = false;
        numerator = abs(numerator);
        denominator = abs(denominator);
        LL int_part = numerator / denominator;
        LL left = numerator - int_part * denominator;
        string int_part_str = to_string(int_part), decimal_part_str = "";
        string result = "";
        if (!tag)   result = "-";
        if (left == 0)      return result + int_part_str;
        map <LL, int> vis;
        int cnt = 0;
        while (left != 0 && vis.count(left) == 0) {
            vis[left] = cnt ++;
            left *= 10;
            LL tmp = left / denominator;
            decimal_part_str += to_string(tmp);
            left = left - tmp * denominator;
        }
        if (left == 0)
            result += int_part_str + "." + decimal_part_str;
        else 
            result += int_part_str + "." + string(decimal_part_str.begin(), decimal_part_str.begin() + vis[left]) + \
                      "(" + string(decimal_part_str.begin() + vis[left], decimal_part_str.end()) + ")";
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.fractionToDecimal(1, 2) << endl;
    cout << solution.fractionToDecimal(2, 1) << endl;
    cout << solution.fractionToDecimal(2, 3) << endl;
    cout << solution.fractionToDecimal(-2147483648, -1) << endl;
    cout << solution.fractionToDecimal(-2147483648, 1) << endl;
    cout << solution.fractionToDecimal(1, 6) << endl;
    return 0;
}
