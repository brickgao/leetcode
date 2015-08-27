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
    string multiply(string num1, string num2) {
        int digital[6001];
        memset(digital, 0, sizeof(digital));
        int i = SZ(num1) - 1;
        while (i >= 0) {
            int j = SZ(num2) - 1;
            int beg_pos = SZ(num1) - 1 - i;
            while (j >= 0) {
                int offset = SZ(num2) - 1 - j;
                digital[beg_pos + offset] += (num1[i] - '0') * (num2[j] - '0');
                int k = offset;
                while (digital[beg_pos +  k] >= 10) {
                    digital[beg_pos + k + 1] += digital[beg_pos + k] / 10;
                    digital[beg_pos + k] %= 10;
                    ++ k;
                }
                j -= 1;
            }
            i -= 1;
        }
        string result = "";
        bool tag = false;
        for (int i = 6000; i >= 0; -- i) {
            if (!tag) {
                if (digital[i] != 0) {
                    tag = true;
                    result += '0' + digital[i];
                }
            }
            else {
                result += '0' + digital[i];
            }
        }
        if (result == "")   return "0";
        else                return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.multiply("2", "3") << endl;
    cout << solution.multiply("111", "111") << endl;
    cout << solution.multiply("9", "9") << endl;
    cout << solution.multiply("999", "999") << endl;
    return 0;
}
