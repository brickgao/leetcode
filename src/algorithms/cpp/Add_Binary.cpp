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
    string addBinary(string a, string b) {
        string result = "";
        int pos1 = SZ(a) - 1, pos2 = SZ(b) - 1;
        int left = 0;
        while (pos1 >= 0 && pos2 >= 0) {
            int tmp = a[pos1] - '0' + b[pos2] - '0' + left;
            result = char('0' + (tmp % 2)) + result;
            left = tmp / 2;
            -- pos1, --pos2;
        }
        while (pos1 >= 0) {
            int tmp = a[pos1] - '0' + left;
            result = char('0' + (tmp % 2)) + result;
            left = tmp / 2;
            -- pos1;
        }
        while (pos2 >= 0) {
            int tmp = b[pos2] - '0' + left;
            result = char('0' + (tmp % 2)) + result;
            left = tmp / 2;
            -- pos2;
        }
        while (left > 0) {
            result = char('0' + (left % 2)) + result;
            left /= 2;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.addBinary("11", "1") << endl;
    return 0;
}
