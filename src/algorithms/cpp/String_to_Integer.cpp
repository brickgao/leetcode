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
    int myAtoi(string str) {
        int pos = 0, result = 0, flag = 1;
        string s = "";
        while (pos < SZ(str) && str[pos] == ' ')    pos += 1;
        if (str[pos] == '-')
            flag = -1, pos += 1;
        else if (str[pos] == '+')
            pos += 1;
        while (pos < SZ(str) && str[pos] == '0')    pos += 1;
        while (pos < SZ(str) || str[pos] == ' ') {
            if (str[pos] > '9' || str[pos] < '0')
                break;
            s += str[pos], pos += 1;
        }
        if (s == "")    return 0;
        for (int i = 0; i < SZ(s); ++ i) {
            result = result * 10 + (s[i] - '0');
        }
        result *= flag;
        if (flag == -1) s = "-" + s;
        char result_s[1000];
        sprintf(result_s, "%d", result);
        int len = strlen(result_s);
        if (len != SZ(s)) {
            if (flag > 0)   return 2147483647;
            else        return -2147483648;
        }
        for (int i = 0; i < len; ++ i)
            if (result_s[i] != s[i]) {
                if (flag > 0)   return 2147483647;
                else        return -2147483648;
            }
        return result;

    }
};


int main() {
    Solution solution = Solution();
    cout << solution.myAtoi("11") << endl;
    cout << solution.myAtoi("010") << endl;
    cout << solution.myAtoi("  -0012a42") << endl;
    cout << solution.myAtoi("-2147483649") << endl;
    return 0;
}
